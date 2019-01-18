/*
Given a binary number set the kth bit of that binary number.
*/

/*
Genrerate a number x with the kth bit set and rest of the bits unset.
Perform OR of n and x.
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
        
        int x = (1<<k);
        cout << (n | x) << "\n";
    }
    return 0;
}
