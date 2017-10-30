#include<bits/stdc++.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<netinet/ip.h>

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 3) {
		cout << "Arguments : [executable] [source ip address] [destination ip address]";
		return 0;
	}
	
	int sockfd;
	struct sockaddr_in peer;
	
	struct send_tcp {
		struct iphdr ip;
		struct tcphdr tcp;
	}packet;
	
	packet.ip.version = 4;
	packet.ip.ihl = 5;
	packet.ip.tos = 0;
	packet.ip.tot_len = htons(40);
	packet.ip.id = 1;
	packet.ip.frag_off = 0;
	packet.ip.ttl = 225;
	packet.ip.protocol = IPPROTO_TCP;
	packet.ip.check = 0;
	packet.ip.saddr = inet_addr(argv[1]);
	packet.ip.daddr = inet_addr(argv[2]);
	
	packet.tcp.source = htons(1234);
	packet.tcp.dest = htons(80);
	packet.tcp.seq = 1;
	packet.tcp.ack_seq = 1;
	packet.tcp.res1 = 4;
	packet.tcp.doff = 4;
	packet.tcp.fin = 1;
	packet.tcp.syn = 1;
	packet.tcp.rst = 1;
	packet.tcp.psh = 1;
	packet.tcp.ack = 1;
	packet.tcp.urg = 1;
	
	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
	if(sockfd < 0)
		cout << "Socket creation failed!\n";
	else
		cout << "Socket created successfully.\n";
	
	peer.sin_family = AF_INET;
	peer.sin_addr.s_addr = inet_addr(argv[1]);
	peer.sin_port = htons(80);
	
	while(true) {
		if(sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&peer, sizeof(peer)) < 0)
			cout << "Sending failed!";
		else
			cout << "Packet Sent.\n";
			
		sleep(1);
	}         
}
