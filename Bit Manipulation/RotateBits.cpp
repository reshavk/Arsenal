/*
Given n & k rotate bits of n by k leftwise and rightwise. The binary representation of n should be considered 
consisting of 16 bits for rotation.
*/

/*
Taking the starting or ending k bits according to the direction of rotation and then performing simpe shift 
operation followed by ORing operation for the starting or ending bits extracted.
*/

/*------------------------------------------------------------------------
                               tenacious
------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        int x, y;
        k = k%16;
        
        x = (1 << k)-1;
        x = (x << (16-k));
        x = n & x;
        x = (x >> (16-k));
        y = (n << k);
        y = (y | x);
        cout << y << "\n";
        
        x = (1 << k)-1;
        x = n & x;
        x = (x << (16-k));
        y = (n >> k);
        y = (y | x);
        cout << y << "\n";
        
    }
    return 0;
}