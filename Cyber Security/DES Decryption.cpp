#include<bits/stdc++.h>
using namespace std;

void displayBits(bool b[], int n) {
	for(int i=0; i<n; i++) {
		cout << b[i];
	}
}

int main() {
	string ct;
	cout << "Enter ciphertext : ";
	cin >> ct;
	
	bool ct_bit[8];
	for(int i=0; i<8; i++) {
		ct_bit[i] = (ct[i]-'0');
	}
	
	cout << "Ciphertext bits : ";
	displayBits(ct_bit, 8);
	cout << "\n";
	
	int ini_per[8] = {6, 2, 4, 5, 1, 3, 0, 7};
	bool temp_bit[8];
	for(int i=0; i<8; i++) {
		temp_bit[ini_per[i]] = ct_bit[i];
	}
	
	for(int i=0; i<8; i++) {
		ct_bit[i] = temp_bit[i];
	}
	
	cout << "After initial permutation : ";
	displayBits(ct_bit, 8);
	cout << "\n";
	
	bool lpt[4], rpt[4];
	for(int i=0; i<4; i++) {
		lpt[i] = ct_bit[i];
	}
	for(int i=4; i<8; i++) {
		rpt[i-4] = ct_bit[i];
	}
	
	cout << "LPT : ";
	displayBits(lpt, 4);
	cout << "\n";
	
	cout << "RPT : ";
	displayBits(rpt, 4);
	cout << "\n";
	
	
	for(int i=0; i<1; i++) {
		int exp_per[6] = {0, 3, 0, 1, 2, 2};
		
		bool exp_bit[6];
		for(int i=0; i<6; i++) {
			exp_bit[i] = lpt[exp_per[i]];
		}
		
		cout << "Expansion of lpt : ";
		displayBits(exp_bit, 6);
		cout << "\n";
		
		bool key[6] = {1, 0, 0, 0, 1, 1};
		for(int i=0; i<6; i++) {
			exp_bit[i] = exp_bit[i] ^ key[i];
		}
		
		cout << "Expanded lpt after XOR : ";
		displayBits(exp_bit, 6);
		cout << "\n";
		
		int sbox_per[4] = {0, 1, 3, 4};
		bool sbox_lpt[4];
		for(int i=0; i<4; i++) {
			sbox_lpt[i] = exp_bit[sbox_per[i]];
		}
		
		cout << "S-box lpt : ";
		displayBits(sbox_lpt, 4);
		cout << "\n";
		
		for(int i=0; i<4; i++) {
			sbox_lpt[i] = sbox_lpt[i] ^ rpt[i];
		}
		
		for(int i=0; i<4; i++) {
			rpt[i] = lpt[i];
			lpt[i] = sbox_lpt[i];
		}
		
		cout << "LPT after XOR and Swapping : ";
		displayBits(lpt, 4);
		cout << "\n";
		
		cout << "RPT after XOR and Swapping : ";
		displayBits(rpt, 4);
		cout << "\n";
	}
	
	bool pt[8];
	for(int i=0; i<4; i++) {
		pt[i] = lpt[i];
	}
	for(int i=4; i<8; i++) {
		pt[i] = rpt[i-4];
	}
	
	
	cout << "Plain text before final permutation : ";
	displayBits(pt, 8) ;
	cout << "\n";
	
	int fin_per[8] = {7, 4, 3, 1, 2, 5, 6, 0};
	for(int i=0; i<8; i++) {
		temp_bit[fin_per[i]] = pt[i];
	}
	
	for(int i=0; i<8; i++) {
		pt[i] = temp_bit[i];
	}
	
	cout << "Plain text after final permutation : ";
	displayBits(pt, 8) ;
	cout << "\n";
	
}
