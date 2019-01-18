//Problem : Given an array, the task is to divide it into two sets S1 and S2 
//such that the absolute difference between their sums is minimum.

//Same as Subset sum, last row of dp matrix gives the sum that is obtainable find the minimom difference from there.

int minimumSumPartition(int a[], int n, int sum) {
    bool dp[n+1][sum+1];
    memset(dp, false, sizeof(dp));

    for(int i=0; i<=n; i++) {
        dp[i][0] = true;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= a[i-1]) {
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-a[i-1]]);
            }
        }
    }

    int ans = INT_MAX;
    for(int i=0; i<=sum; i++) {
        if(dp[n][i]) {
            ans = min(ans, abs(2*i -sum));
            //cout << i << " " << abs(2*i - sum) << " " << ans << "\n";
        }
    }
    return ans;
}
