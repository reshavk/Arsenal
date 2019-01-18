// Problem : Given a buliding having n storeys and we have e no. of eggs. We have to find the minimum number
//of trials required to know what is the maximum height from where the egg can be dropped without breaking.
//For further elaboration of problem statement : watch egg droping puzzle fro ted-ed
//For further elaboration of solution : watch tushar roy

int minimumTrials(int n, int e) {
    int dp[e+1][n+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i=0; i<=n; i++) {
        dp[1][i] = i;
    }
    
    for(int i=2; i<=e; i++) {
        for(int j=1; j<=n; j++) {
            if(i > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                int x = INT_MAX;
                for(int k=1; k<=j; k++) {
                    x = min(x, max(dp[i-1][k-1], dp[i][j-k]));
                }
                dp[i][j] = 1 + x;
            }
        }
    }
    
    return dp[e][n];
}

//Solution aims at thinking for each storey if the egg is dropped, two cases arise either the egg breaks or it doesn't
//For both the cases depending on the no. of eggs remaining ans the no. of storeys left to check we get two values me take maximum of two
//For all storeys we find this value and select the minimum among them, ans then add 1 to this minimum value 
//1 is added to take into consideration the value which exists due to checking of that particular floor.