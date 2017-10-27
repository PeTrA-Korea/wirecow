
/*
* KU Konkuk University
* Security FACT
*/

#include <netinet/in.h>
#include <netinet/ether.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

int main(int argc, char* argv[]){
	char* dev;
	char errbuf[PCAP_ERRBUF_SIZE];
	const u_char* packet;
	pcap_t* handle;
	bpf_u_int32 mask;
	bpf_u_int32 net;

	if(argc == 1){
		printf("ERROR : INPUT THE DEVICE NAME :(\n");
		printf("wirecow [device name]");
	}
	
	system("clean");
	
	if(dev == NULL){
		fprintf(stderr, "COULDN'T FIND DEFAULT DEVICE : %s\n", errbuf);
		return 2;
	}
	
	if(pcap_lookupnet(dev, &net, &mask, erruf) == -1){
		fprintf(stderr, "COULDN'T GET NETMASK FOR DEVICE %s : %s\n", dev, errbuf);
		net = 0;
		mask = 0;
		return 2;
	}
	
	handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
	
	if(handle == NULL){
		fprintf(stderr, "COULDN'T OPEN DEVICE %s : %s\n", dev, errbuf);
		return 2;
	}
	
	if(pcap_compile(handle, &fp
	
	

	
}
