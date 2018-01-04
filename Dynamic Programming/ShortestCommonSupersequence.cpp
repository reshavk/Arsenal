//Problem : Given two strings a and b. Find the no. of charachters in the supersequence of a and b.
//Supersequence of a and b is a sequence of charachters that contain both a and b string as subsequence.

int scS(string a, string b) {
    int dp[b.size()+1][a.size()+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i=0; i<=a.size(); i++) {
        dp[0][i] = i;
    }
    for(int i=0; i<=b.size(); i++) {
        dp[i][0] = i;
    }
    
    for(int i=1; i<=b.size(); i++) {
        for(int j=1; j<=a.size(); j++) {
            if(a[j-1] == b[i-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else {
                dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
            }
        }
    }
    
    return dp[b.size()][a.size()];
}

//Similar to loongest common subsequence problem. Draw a 2D matrix and think of supersequence at each pass.
//Process will become clear.