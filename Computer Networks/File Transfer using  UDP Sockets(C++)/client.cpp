#include<bits/stdc++.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fstream>

#define BUFFLEN 512
using namespace std;

int main() {
	int sockfd;
	struct sockaddr_in ser;
	
	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(sockfd < 0)
		cout << "Socket creation failed!\n";
	else
		cout << "Socket created successfully.\n";
	
	ser.sin_family  = AF_INET;
	ser.sin_addr.s_addr = inet_addr("127.0.0.1");
	ser.sin_port = htons(8000);
	
	cout << "Connected to server successfully.\n";
		
	int sersize = sizeof(ser);
	char buff[512];
	char x;
	while(true) {
		char m[] = "Connected.\n";
		sendto(sockfd, m, sizeof(m), 0, (struct sockaddr*)&ser, sizeof(ser));	
		
		memset(buff, 0, sizeof(buff));
		recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&ser, (socklen_t*)&sersize);
		cout << buff;
	
		char fname[20];
		cin >> fname;
		sendto(sockfd, fname, sizeof(fname), 0, (struct sockaddr*)&ser, sizeof(ser));
		
		char copied[20] = {};
		for(int i=0,j=0 ; i<strlen(fname); i++,j++) {
			if(fname[i] == '.') {
				copied[j] = '1';
				j++;
			}
			copied[j] = fname[i];
		}
		cout << copied << "\n";
		
		int siz;
		recvfrom(sockfd, &siz, sizeof(siz), 0, (struct sockaddr*)&ser, (socklen_t*)&sersize);
		cout << siz;
		
		FILE * f = fopen(copied, "wb");
		memset(buff, 0, sizeof(buff));
		int i=1;
		
		while(i*BUFFLEN < siz) {
			recvfrom(sockfd, buff, BUFFLEN, 0, (struct sockaddr*)&ser, (socklen_t*)&sersize);
			fwrite(buff, BUFFLEN, 1, f);
			memset(buff, 0, sizeof(buff));
			i++;
		}
		
		recvfrom(sockfd, buff, (siz%BUFFLEN), 0, (struct sockaddr*)&ser, (socklen_t*)&sersize);
		fwrite(buff, (siz%BUFFLEN), 1, f);
		
		cout << "File received successfully.";
		return 0;
	}
	
}
