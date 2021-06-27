/******************************************
 * Filename : traffic_analysis.c
 * Time     : 2021-06-27 12:00
 * Author   : 小骆
 * Dcription: 
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

#include <signal.h>
#include <pcap.h>

#include "traffic_analysis.h"

//是否退出主循环标志位 0表示循环收包解析，1表示退出循环程序结束
int is_loop_break = 0;

pcap_t *g_pcap = NULL;

// 统计收到的数据包个数
int packet_num = 0;

/*
 * 函数名：stop_work
 * 功能：信号处理函数回调，接收停止信号，将退出标志置位。
 * 参数：int sig；   传入的信号。
 * 返回值：无
 * */
void stop_work(int sig){
    if(SIGINT == sig){
        if(g_pcap != NULL){
            pcap_breakloop(g_pcap);
        }
    }
    return ;
}

static void parse_ip_pkt(const u_char *sp, bpf_u_int32 len){
    ip_hdr *ih = (ip_hdr*)(sp);
    printf("version:[%d], tot_len:[%u] ttl:[%d], protocol:[%02x]\n",
           ih->version, ntohs(ih->tot_len), ih->ttl, ih->protocol);
    return ;
}

static void Packet_handle(u_char *user, const struct pcap_pkthdr *h, u_char *sp){
    packet_num++;
    pcap_dumper_t *dumper = (pcap_dumper_t *)user;

    bpf_u_int32 len = h->caplen;

    eth_hdr *eh = (eth_hdr*)sp;
    parse_ip_pkt(sp+sizeof(eth_hdr), len - sizeof(eth_hdr));
    pcap_dump(user, h, sp);
    pcap_dump_flush(dumper);

    return 0;
}

int main(int argc, char *argv[]){

    int ret = -1;
    //参数校验，需要输入网口名和需要生成pcap数据包文件名字
    if(argc != 3){
        fprintf(stderr, "Usage:\n"
                        "\t./%s interface pcap_file_name \n"
                        );
        exit(1);
    }

    /* 注册信号处理函数，接收Ctrl+C停止信号退出循环 */
    signal(SIGINT, stop_work);

    const char *interface_name = argv[1];
    const char *pcap_file_name = argv[2];

    /* 设置默认参数 */
    int snaplen = 65535;    //设置每个数据包的捕捉长度。
    int promisc = 1;        //是否打开混杂模式
    int to_ms = 1000;       //设置获取数据包的超时时间（ms）
    char ebuf[PCAP_ERRBUF_SIZE] = {0};  //存放错误信息的数组

    //调用libpcap接口函数
    pcap_t *handle = pcap_open_live(interface_name, snaplen, promisc, to_ms, ebuf);
    if(handle == NULL){
        printf("pcap_open_live failed, %s.\n", ebuf);
        goto ERR;
    }

    printf("pcap_open_live success.\n");
    g_pcap = handle;

    //开始开始编译规则
    struct bpf_program program;

    char bpf_buf[512] = "port 80";  //指定抓取80端口的数据包
    int optimize = 0;               //是否需要优化表达式

    //调用libpcap接口对表达式进行编译
    if(pcap_compile(handle, &program, bpf_buf, optimize, 0) != 0){
        printf("pcap");
        goto ERR;
    }
    printf("pcap_compile success.\n");

    //调用libpcap接口设置过滤条件
    if (pcap_setfilter(handle,  &program) != 0){
        printf("pcap_setfilter failed, %s\n");
        goto ERR;
    }
    printf("pcap_setfilter success.\n");

    pcap_dumper_t *dumper = pcap_dump_open(handle, pcap_file_name);
    if(dumper == NULL){
        printf("pcap_dump_open failed\n");
        goto ERR;
    }

    //主循环负责进行数据包的处理
    pcap_loop(handle, 0, Packet_handle, dumper);

    //刷新数据到数据包文件
    pcap_dump_flush(dumper);

    printf("Stop capture the packet, total:[%d]\n""Program 3s will exit ...\n", packet_num);
    sleep(3);
    ret = 0;

// 释放资源
ERR:
    if(dumper != NULL){
        pcap_dump_close(dumper);
    }
    if (handle != NULL){
        pcap_close(handle);
    }

    return ret;
}