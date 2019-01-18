int n; //total no. of coins available
int t; //total amount

cin >> n >> t;
int d[n+1] //denomination of different coins available

int dp[n+1][t+1] = {}; 

for(int i=1; i<=n; i++) {
    cin >> d[i];
}

for(int i=1; i<=n; i++) {
    for(int j=0; j<=t; j++) {
      if(j == 0)
        dp[i][j] = 0;
      else if(dp[i] > j) {
        dp[i][j] = dp[i-1][j];
      }
      else {
        dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-d[i]]);
      }
   }
}

cout << dp[n][k] << "\n"; //minimum no. of coins that will be required to obtain an amount of t using n coins of denomination d[n]
