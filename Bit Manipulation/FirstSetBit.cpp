/*
Program to find the first set bit in a given number.
*/

/*
Simply take the and of x & -x.
Since -x represents two's complement of the number which has the first set bit 1 same and all the other inverted.
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
        
        if(n == 0) {
            cout << 0 << "\n";
        }
        else {
            cout << log2((n&-n)) + 1 << "\n";
        }
    }
    return 0;
}