int n; //no. of coins
int t; //total amount to be obtained by any combination of coins

cin >> n >> t;

int d[n+1]; //denominations of coins available
int dp[n+1][t+1] = {};

for(int i=1; i<=n; i++) {
    cin >> d[i];
}

for(int i=1; i<=n; i++) {
    for(int j=0; j<=t; j++) {
        if(j == 0) {
            dp[i][j] = 1;
        }
        else if(d[i] > j) {
            dp[i][j] = dp[i-1][j];
        }
        else {
            dp[i][j] = dp[i-1][j] + dp[i][j - d[i]];
        }
    }
}

cout << dp[n][t] << "\n"; //Total ways to obtain amount t using n coins of denomination d[n]
