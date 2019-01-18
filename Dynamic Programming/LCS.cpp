int n1 //length of first string
int n2 //length of second string

string s1, s2;
dp[n1+1][n2+1] = {};

for(int i=1; i<=n1; i++) {
	for(int j=1; j<=n2; j++) {
		if(s1[i] == s2[j]) {
			dp[i][j] = dp[i-1][j-1] + 1;
		}
		else {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
}

cout << dp[n][n];

