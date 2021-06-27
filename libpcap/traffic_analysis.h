/******************************************
 * Filename : traffic_analysis.h
 * Time     : 2021-06-27 12:00
 * Author   : 小骆
 * Dcription: 
*******************************************/

#ifndef HERA_CODE_TRAFFIC_ANALYSIS_H
#define HERA_CODE_TRAFFIC_ANALYSIS_H

typedef struct _eth_hdr{
    unsigned char dstmac[6];    //目的mac地址
    unsigned char srcmac[6];    //源mac地址
    unsigned short eth_type;    //以太网类型
}eth_hdr;

#endif
