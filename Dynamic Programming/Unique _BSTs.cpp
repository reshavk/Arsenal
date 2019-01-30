/*
Given an integer N, how many structurally unique binary search trees are there that store values 1...N?
*/

/*------------------------------------------------------------------------
                               tenacious
------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int dp[12];
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2; i<12; i++) {
        int sum = 0;
        for(int j=0; j<i; j++) {
            sum += dp[j] * dp[i-j-1];
        }
        dp[i] = sum;
    }
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        cout << dp[n] << "\n";
    }
    return 0;
}