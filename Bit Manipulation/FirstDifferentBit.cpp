/*
Given two numbers find the first different bit in the binary representation of those nummbers.
*/

/*
Take the XOR of the two numbers to generate the binary representation which contains 1 wherever different bits are
present. Now the problem reduces to finding the first set bit from the binary representationa and we know how
to do that.
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
        int n, m;
        cin >> n >> m;
        
        int x = n ^ m;
        if(x == 0) {
            cout  << -1 << "\n";
        }
        else {
            cout << log2(x&-x)+1 << "\n";
        }
    }
    return 0;
}