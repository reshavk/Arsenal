#include<bits/stdc++.h>
#include<fstream>

using namespace std;

int convert(char *data, int pos) {
	int num = 0;
	for(int j=pos+1; j>pos-1; j--) {
		num *= 16;
		switch(data[j]) {
			case 'a' : num += 10; break;
			case 'b' : num += 11; break;
			case 'c' : num += 12; break;
			case 'd' : num += 13; break;
			case 'e' : num += 14; break;
			case 'f' : num += 15; break;
			case ' ' : break;
			default : num += (data[j] - 48);
		}
	}
	return num;
}

int main() {
	char fname[20] = {};
	cout << "Enter name of sniffer log file : ";
	cin >> fname;
	
	ifstream fin;
	fin.open(fname, ios::in);
	int type, protocol;
	
	char data[512] = {};
	int i = 1;
	
	while(!fin.eof()) {
		fin.getline(data,512);
		if(strcmp(data, "") == 0) {
			break; 
		}
		cout << "\n\n" << "Captured packet no. " << i++ << " : " << "Data -> " << data << "\n";
		int pos = 0, j;
		for(j=0; pos < 12; j++){
			if(data[j] == ' ')
				pos++;
		}
		type = convert(data, j) * 100; 
		for( ; pos < 13; j++){
			if(data[j] == ' ')
				pos++;
		}
		type += convert(data, j);
		cout << "Type -> ";
		switch(type) {
			case 800 : cout << "IP\n"; break;
			case 806 : cout << "ARP\n"; break;
			default : cout << "Packet type " << type << "\n";
		}
		
		for( ; pos < 23; j++){
			if(data[j] == ' ')
				pos++;
		}
		protocol = convert(data, j);
		cout << "Protocol -> ";
		switch(protocol) {
			case 0 : cout << "HOPOPT\n"; break;
			case 1 : cout << "ICMP\n"; break;
			case 6 : cout << "TCP\n"; break;
			case 17 : cout << "UDP\n"; break;
			default : cout << "Protocol type " << protocol << "\n";
		}
		
		cout << "Source IP address -> ";
		for( ; pos < 26; j++){
			if(data[j] == ' ')
				pos++;
		}
		cout << convert(data, j) << ".";
		for( ; pos < 27; j++){
			if(data[j] == ' ')
				pos++;
		}
		cout << convert(data, j) << ".";
		for( ; pos < 28; j++){
			if(data[j] == ' ')
				pos++;
		}
		cout << convert(data, j) << ".";
		for( ; pos < 29; j++){
			if(data[j] == ' ')
				pos++;
		}
		cout << convert(data, j) << "\n";
		
		cout << "Destination IP address -> ";
		for( ; pos < 30; j++){
			if(data[j] == ' ')
				pos++;
		}
		cout << convert(data, j) << ".";
		for( ; pos < 31; j++){
			if(data[j] == ' ')
				pos++;
		}
		cout << convert(data, j) << ".";
		for( ; pos < 32; j++){
			if(data[j] == ' ')
				pos++;
		}
		cout << convert(data, j) << ".";
		for( ; pos < 33; j++){
			if(data[j] == ' ')
				pos++;
		}
		cout << convert(data, j) << "\n"; 
		
	}
	fin.close();
	return 0;	
}
