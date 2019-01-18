#include<bits/stdc++.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fstream>

#define BUFFLEN 512
using namespace std;

int fsize(char* fname) {
	FILE* f;
	f = fopen(fname, "r");
	fseek(f, 0, SEEK_END);
	int n;
	n = (int)ftell(f);
	fclose(f);
	return n;
}

int main() {
	int ssockfd;
	struct sockaddr_in ser, ser_other;
	
	ssockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(ssockfd < 0)
		cout << "Socket creation failed!\n";
	else
		cout << "Socket created successfully.\n";
	
	ser.sin_family = AF_INET;
	ser.sin_addr.s_addr = INADDR_ANY;
	ser.sin_port = htons(8000);
	
	if(bind(ssockfd, (struct sockaddr*)&ser, sizeof(ser)) < 0) 
		cout << "Socket binding failed!\n";
	else
		cout << "Socket binding successful.\n";
	
	int sersize = sizeof(ser_other);
	
	char buffer[512], x;
	while(true) {	
		recvfrom(ssockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&ser_other, (socklen_t*)&sersize);
		cout << buffer; 
	
		char msg[] = "Enter name of file to be transffered : ";
		sendto(ssockfd, msg, sizeof(msg), 0, (struct sockaddr*)&ser_other, sersize);
	
		char fname[20];
		recvfrom(ssockfd, fname, sizeof(fname), 0, (struct sockaddr*)&ser_other, (socklen_t*)&sersize);
		cout << "Filename : " << fname <<"\n";
		
		int siz = fsize(fname);
		sendto(ssockfd, &siz, sizeof(siz), 0, (struct sockaddr*)&ser_other, sersize);
		cout << siz;
		
		FILE * f = fopen(fname, "rb");
		memset(buffer, 0, sizeof(buffer));
		fread(buffer, BUFFLEN, 1, f);
		int i=1;
		
		while(i*BUFFLEN < siz) {
			sendto(ssockfd, buffer, BUFFLEN, 0, (struct sockaddr*)&ser_other, sersize);
			memset(buffer, 0, BUFFLEN);
			fread(buffer, BUFFLEN, 1, f);
			i++;
		}
		
		memset(buffer, 0, sizeof(buffer));
		fread(buffer, (siz%BUFFLEN), 1, f);
		sendto(ssockfd, buffer, (siz%BUFFLEN), 0, (struct sockaddr*)&ser_other, sersize);
		
		cout << "File sent successfully.";
		return 0;
	}
	
	
	
}
