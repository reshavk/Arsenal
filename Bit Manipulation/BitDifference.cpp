/*
Given two numbers a and b calculate the total no. of different bits in the binary representation of a and b.
*/

/*
Calculate x = a XOR b;
Now loop through all set bits calcuating the first set bit of x and again making it 0.
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
        int a, b;
        cin >> a >> b;
        
        int x = a^b;
        
        int y = (x&-x);
        int ans = 0;
        while(y != 0) {
            ans++;
            x = x^y;
            y = (x&-x);
        }
        
        cout << ans << "\n";
    }
    return 0;
}