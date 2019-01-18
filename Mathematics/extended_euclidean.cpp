/*------------------------------------------------------------------------
                                tenacious								
------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

int d, x, y;
void extended_euclidean(int a, int b) {
    if(b == 0) {
        d = a;
        x = 1;
        y = 0;
    }
    else {
        extended_euclidean(b, a%b);
        int temp = x;
        x = y;
        y = temp - (a/b)*y;
    }
}
//If A and B are coprime, then x is multiplicative inverse of A under modulo B and y is multiplicative inverse of B under modulo A.


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


}