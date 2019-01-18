/*
Given a number n, for each pair of odd and even bits swap odd-even bits.
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
        int n;
        cin >> n;
        
        int even_bits = n & 0xAAAA;
        int odd_bits = n & 0x5555;
        
        odd_bits = odd_bits << 1;
        even_bits = even_bits >> 1;
        
        cout << (odd_bits | even_bits) << "\n";
    }
    
}