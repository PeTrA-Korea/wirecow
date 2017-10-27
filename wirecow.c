
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
	int res;
	char* dev;
	char errbuf[PCAP_ERRBUF_SIZE];
	char filter_exp[] = "port 80";
	const u_char* packet;
	pcap_t* handle;
	bpf_u_int32 mask;
	bpf_u_int32 net;
	struct bpf_program fp;
	struct pcap_pkthdr* header;

	if(argc == 1){
		printf("ERROR : INPUT THE DEVICE NAME :(\n");
		printf("wirecow [device name]");
	}
	
	dev = argv[1];

	system("clean");
	
	if(dev == NULL){
		fprintf(stderr, "COULDN'T FIND DEFAULT DEVICE : %s\n", errbuf);
		return 2;
	}
	
	if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1){
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
	/*
	if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1){
		fprintf(stderr, "COULDN'T PARSE FILTER %s : %s\n", filter_exp, pcap_geterr(handle));
	return 2;
	}
	
	if(pcap_setfilter(handle, &fp) == -1){
		fprintf(stderr, "COULDN'T INSTALL FILTER %s : %s\n", filter_exp, pcap_geterr(handle));
	return 2;
	}
	*/
	while(1){
		res = pcap_next_ex(handle, &header, &packet);
		printf("JACKED A PACKET WITH LENGTH OF [%d]\n", header->len);
		if(res == 0){
			continue;
		}else if(res == -1){
			printf("ERROR : FAIL TO READ THE PACKETS\n");
			continue;
		}
	}
	return 0;

	
}
