cc=gcc

target=capture_and_save_test

cflags=-Wall -g -I../include/ libpcap.a

all:$(target)
	@echo "compile success"

capture_and_save_test: traffic_analysis.c
	$(cc) $(cfalgs) $< -o $@  $(cflags)

clean:
	rm *.o *.pcap $(target) core* a.out -f 
