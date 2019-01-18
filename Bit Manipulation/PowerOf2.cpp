/*
Given a number check whether it is a power of 2.
*/

/*
Get the first set bit of the number if it equals the number then answer is yes otherwise no.
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
        long long n;
        cin >> n;
        
        if(n == 0) {
            cout << "NO\n";
            continue;
        }
        
        if( (n&-n) == n) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
