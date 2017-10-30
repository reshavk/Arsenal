#include<bits/stdc++.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<netinet/udp.h>

using namespace std;

int main(int argc, char* argv[]) {
	
	if(argc != 3) {
		cout << "Invaild arguments supplied\n";
	}
	
	int udp_socket;
	struct sockaddr_in ser;
	
	struct send_udp {
		struct iphdr ip;
		struct udphdr udp;
	}packet;
	
	packet.ip.version = 4;
	packet.ip.ihl = 5;
	packet.ip.tos = 0;
	packet.ip.tot_len = htons(40);
	packet.ip.id = 1;
	packet.ip.frag_off = 0;
	packet.ip.ttl = 255;
	packet.ip.protocol = IPPROTO_UDP;   
	packet.ip.check = 0;
	packet.ip.saddr = inet_addr(argv[1]);
	packet.ip.daddr = inet_addr(argv[2]);
	
	packet.udp.source = htons(1234);
	packet.udp.dest = htons(80);   
	packet.udp.len = htons(sizeof(struct udphdr));
	
	udp_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(udp_socket < 0)
		cout << "Socket creation failed!\n";
	else
		cout << "Socket created.\n";
	
	ser.sin_family = AF_INET;
	ser.sin_addr.s_addr = inet_addr(argv[1]);
	ser.sin_port = htons(80);
	
	while(true) {
		if(sendto(udp_socket, &packet, sizeof(packet), 0, (struct sockaddr*)&ser, sizeof(ser)) < 0)
			cout << "Sending failed!\n";
		else
			cout << "Packet Sent!\n";
		sleep(1); 
	}
}
