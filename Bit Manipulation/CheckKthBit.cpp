/*
Check whether the kth bit is set or not.
*/

/*
Make a number x by right shifting bits by k pisition in binary representation of 1.
Take AND of this number x with the given number. If result is same as x then bit is set else not.
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
        
        int x = 1 << k;
        if( (n&x) == x ) {
            cout << "Yes\n";
        }
        else {
            cout <<"No\n";
        }
    }
    return 0;
}