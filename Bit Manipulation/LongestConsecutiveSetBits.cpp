/*
Given a number n we have to find the length of the longest consecutive set bits in the number. 
*/

/*
CONCEPT : Whenever we and (x) & (x << 1) we basically remove a trailing 1 i.e. a 1 just after a zero.
So if we repeatedly perform this operation until x becomes 0 we will get what's required.
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
        
        int ans = 0;
        while(n != 0) {
            n &= (n << 1);
            ans++;
        }
        
        cout << ans << "\n";
    }
    return 0;
}