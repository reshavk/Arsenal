#include<bits/stdc++.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

using namespace std;

char msg[2000];
void checkCRC(char buffer[]) {
	int m[20], crc[10], g[] = {1,0,0,0,0,0,1,1,1};
	int gs = 9, fs = 8;
	int n = fs + gs - 1;
	
	for(int i=0; i<n; i++) {
		m[i] = (buffer[i] - '0');
	}
	
	for(int i=0; i<gs; i++) {
		crc[i] = m[i];
	}

	int i=0, j;
	while(i < n) {
		if(crc[0] == 1) {
			for(j=1; j<gs; j++) {
				crc[j-1] = crc[j] ^ g[j];
			}
		}
		else{
			for(j=1; j<gs; j++) {
				crc[j-1] = crc[j] ^ 0;
			}
		}
		if(i+j == n)
			break;
		crc[j-1] = m[i+j];
		i++;
	}
	
	int sum = 0;
	for(int i=0; i<gs-1; i++) {
		sum += crc[i];
	}
	
	if(sum) {
		strcpy(msg, "Error in transmission !");
	}
	else{
		strcpy(msg, "No errror in transmission.");
	}
}

int main() {
	int ssockfd, csockfd;
	struct sockaddr_in ser;
	
	ssockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(ssockfd < 0) 
		cout << "Socket creation falied !\n";
	else
		cout << "Socket creation successful.\n";
	
	ser.sin_family = AF_INET;
	ser.sin_addr.s_addr = INADDR_ANY;
	ser.sin_port = htons(6000);
	
	if(bind(ssockfd, (struct sockaddr*)&ser, sizeof(ser)) < 0) {
		cout << "Binding failed !\n";
	} 
	else {
		cout << "Binding successful .\n";
	}
	
	listen(ssockfd, 1);
	
	int sersize = sizeof(ser);
	csockfd = accept(ssockfd, (struct sockaddr*)&ser, (socklen_t *)&sersize);
	if(csockfd < 0) 
		cout << "Client connection request rejected !\n";
	else
		cout << "Client connection request accepted.\n";
	
	char buffer[2000];
	while(true) {
		recv(csockfd, buffer, sizeof(buffer), 0);
		cout << "Do you want to introduce error ? (y/n) : ";
		char res;
		cin >> res;
		
		if(res == 'y') {
			buffer[3] ^= 1;
		}
		memset(msg,0,sizeof(msg));
		checkCRC(buffer);
		
		send(csockfd, msg, sizeof(msg), 0);
	}
	
}
