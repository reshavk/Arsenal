//Problem : Frog steps either 1, 2 or 3 steps to go to top. In how many ways it reaches the top?

//Try building 2D matri for visualizing the situation first.
//The pattern is trivial and will be identified.

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        int dp[n+1] = {};
        dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 4;
        int prev = dp[1]+dp[2];
        for(int i=4; i<=n; i++) {
            prev += (dp[i-1] - dp[i-4]);
            dp[i] = prev;
        }
        cout << dp[n] << "\n";
    }
    return 0;
}