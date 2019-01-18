//Problem : To fnd the maximum no. of segments in which a rod of length N can be divided given segments should be of length x, y, z

int maxCutSegment(int n, int x, int y, int z) {
   int dp[n+1];
   memset(dp, -1, sizeof(dp));
   dp[0] = 0;

   for(int i=0; i<=n; i++) {
        if(i>=x && dp[i-x] != -1) {
            dp[i] = max(dp[i], dp[i-x]+1);
        }
        if(i>=y && dp[i-y] != -1) {
            dp[i] = max(dp[i], dp[i-y]+1);
        }
        if(i>=z && dp[i-z] != -1) {
            dp[i] = max(dp[i], dp[i-z]+1);
        }
   }

   return dp[n];
}
