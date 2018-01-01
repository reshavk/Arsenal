//Problem : Given two strings a and b what is the minimum no. of operations required to convert secind string into first.
//			Operation allowed : 1. Update 	2. Delete		3.Insert

int editDistance(string a, string b) {
	int dp[b.size() + 1][a.size() + 1] = {};

	for(int i=0; i<=a.size(); i++) {
		dp[0][i] = i;
	}

	for(int i=0; i<=b.size(); i++) {
		dp[i][0] = i;
	}

	for(int i=1; i<=b.size(); i++) {
		for(int j=1; j<=a.size(); j++) {
			if(a[j-1] == b[i-1]) {
				dp[i][j] = dp[i-1][j-1];
			}
			else {
				dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
			}
		}
	}

	return dp[b.size()][a.size()];
}