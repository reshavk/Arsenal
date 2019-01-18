#include<bits/stdc++.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

using namespace std;

char buffer[2000];
void CRC(char x) {
	int m[20] = {}, crc[10] = {}, g[9] = {1,0,0,0,0,0,1,1,1};
	
	bitset<8> msg (x);	
	for(int i=0; i<8; i++) {
		m[i] = (int)msg[i];
	}
	
	cout << "Message frame : ";
	for(int i=0; i<8; i++) {
		cout << m[i];
	}
	cout << "\n";
	
	int gs = 9, fs = 8;
	int n = fs + gs - 1;
	for(int i=0; i<gs-1; i++) {
		m[fs + i] = 0;
	}
	cout << "Message frame after appending zeroes : ";
	for(int i=0; i<n; i++) {
		cout << m[i];
	}
	cout << "\n";
	
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
	
	cout << "Cyclic Redundency check bits are : ";
	for(int i=0; i<gs-1; i++) {
		cout << crc[i];
	}
	cout << "\n";
	
	for(int i=0; i<gs-1; i++) {
		m[fs+i] = crc[i];
	}
	
	cout << "Transmitted message : ";
	for(int i=0; i<n; i++) {
		cout << m[i];
		buffer[i] = (m[i] + '0');
	}
	cout << "\n"; 
	
}

int main(){
	int sockfd;
	struct sockaddr_in ser;
	
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sockfd < 0)
		cout << "Socket creation failed !\n";
	else
		cout << "Socket creation successful.\n";
	
	ser.sin_family = AF_INET;
	ser.sin_addr.s_addr = inet_addr("127.0.0.1");
	ser.sin_port = htons(6000);
	
	if(connect(sockfd, (struct sockaddr*)&ser, sizeof(ser)) < 0){
		cout << "Connecting to server failed !\n";
	}
	else {
		cout << "Connection to server established !\n";
	}
	
	char msg[2000];
	while(true) {
		cout << "Enter charachter to be transmitted : ";
		char x;
		cin >> x;
		
		memset(buffer, 0, sizeof(buffer));
		CRC(x);
		
		send(sockfd, buffer, sizeof(buffer), 0);
		
		memset(msg, 0, sizeof(msg));
		recv(sockfd, msg, sizeof(msg), 0);
		cout << "Server : " << msg << "\n";
	}
}

