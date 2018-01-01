//Problem : Given a sequence of mubers find the longest increasing subsequence

int LIS(int a[], int n) {
	int dp[n] = {};
	dp[0] = 1;

	for(int i=1; i<n; i++) {
		int val = 1;
		for(int j=0; j<i; j++) {
			if(a[j] < a[i]) {
				val = max(val, dp[j]+1);
			}
		}
		dp[i] = val;
	}

	int ans =  INT_MIN;
	for(int i=0; i<n; i++) {
		ans = max(ans, dp[i]);
	}

	return ans;
}