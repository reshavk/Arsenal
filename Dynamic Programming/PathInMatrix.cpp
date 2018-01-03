/*Problem : Given a N X N  matrix Matrix[N][N] of positive integers.  There are only three possible moves from a cell Matrix[r][c].

1. Matrix[r+1][c]

2. Matrix[r+1][c-1]

3. Matrix[r+1][c+1]

Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        int a[n][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> a[i][j];
            }
        }
        
        int dp[n][n];
        
        for(int i=0; i<n; i++) {
            dp[0][i] = a[0][i];
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(j != 0 && j != n-1) {
                    dp[i][j] = max(a[i][j] + dp[i-1][j], max(a[i][j]+dp[i-1][j-1], a[i][j]+dp[i-1][j+1]));
                }
                else if(j == 0) {
                    dp[i][j] = max(a[i][j]+dp[i-1][j], a[i][j]+dp[i-1][j+1]);
                }
                else if(j == n-1) {
                    dp[i][j] = max(a[i][j]+dp[i-1][j], a[i][j]+dp[i-1][j-1]);
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            ans = max(dp[n-1][i], ans);
        }
        
        cout << ans << "\n";
    }
    return 0;
}