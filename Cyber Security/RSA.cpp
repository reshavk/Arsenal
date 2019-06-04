#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while(b) {
		int temp = (a % b);		
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	
	double p, q;
	p = 3.0;
	q = 7.0;
	cout << "Random Prime number p = " << p <<"\n";
	cout << "Random Prime number q = " << q <<"\n";

	double n = p*q;
	cout << "n generated from p and q : " << n << "\n";
	double totient = (p-1)*(q-1);
	cout << "Totient(n) : " << totient << "\n";	

	double e;
	for(int i=2; i<n; i++) {
		if(gcd(i, totient) == 1) {
			e = i;
			break;	
		}
	}

	cout << "Public key pair (e,n) : " << "(" << e << "," << n << ")\n";
	
	double d;
	for(int k=1; k<n; k++) {
		if (fmod((totient*k + 1),e) == 0) {
			d = (totient*k + 1)/e;
			break;
		}
	}

	cout << "Private key pair (d,n) : " << "(" << d << "," << n << ")\n";
	

	double m;
	cout << "Enter the value of msg : ";
	cin >> m;

	double c = fmod(pow(m,e),n);
	cout << "Cipher text : " << c << "\n";

	double rm;
	rm = fmod(pow(c,d),n);
	cout << "Original text : " << rm << "\n";


	return 0;
	

}
