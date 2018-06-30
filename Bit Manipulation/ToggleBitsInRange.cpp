/*
Given a number n toggle all bits in a given range l to r in the binary representation of the number. 
*/

/*
Genreate an integer having all bits set for the range l to r in the binary representation of the number.
Take XOR of this integer with the given number.
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
        int n, l, r;
        cin >> n >> l >> r;
        
        int a = ((1<<r)-1);
        int b = ((1<<(l-1))-1);
        int x = a ^ b;
        
        cout << (n ^ x) << "\n";
        
    }
    return 0;
}