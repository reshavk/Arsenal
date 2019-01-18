#include<bits/stdc++.h>
#include<fstream>

using namespace std;
int main() {
	ifstream fin;
	fin.open("out.tr",ios::in);
	
	long long s = 0, r = 0, d = 0, tcp = 0, udp = 0, cbr = 0, ack = 0;
	
	while(!fin.eof()) {
		string str[12];
		for(int i=0; i<12; i++) {
			fin >> str[i];
		}
		for(int i=0; i<12; i++) {
			cout << str[i] << " ";
		}
		cout << "\n";
		if(str[0] == "+") s++;
		if(str[0] == "d") d++;
		if(str[0] == "r") r++;
		
		if(str[4] == "tcp") tcp++;
		if(str[4] == "udp") udp++;
		if(str[4] == "ack") ack++;
		if(str[4] == "cbr") cbr++;
	}
	
	cout << "Total packets sent : " << s << "\n";
	cout << "Total packets received : " << r << "\n";
	cout << "Total packets dropped : " << d << "\n";
	cout << "Packets sent ratio : " << (r/(double)s)*100 << "\n";
	cout << "Packets dropped ratio : " << (d/s)*100 << "\n";
	cout << "Total tcp packets : " << tcp << "\n";
	cout << "Total udp packets : " << udp << "\n";
	cout << "Total cbr packets : " << cbr << "\n";
	cout << "Total ack packets : " << ack << "\n";
}
