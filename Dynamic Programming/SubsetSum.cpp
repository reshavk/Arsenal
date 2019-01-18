//Problem : Given a set of elements check wheteher the elementas can be partitioned into two subsets having same sum

//Recursive Solution (O(2^n))
bool partition_recursive(int a[], int n, int sum) {
	if(n < 0 && sum != 0) {
		return false;
	}
	if(sum == 0) {
		return true;
	}
	if(a[n-1] > sum) {
		return partition_recursive(a, n-1, sum);
	}
	else {
		return partition_recursive(a, n-1, sum-a[n-1]) || partition_recursive(a, n-1, sum);
	}
}

//DP solution (O(sum/2 * n) i.e. O(n^2))
bool partition_dp(int a[], int n, int sum) {
	bool part[n+1][sum+1] = {};

	for(int i=0; i<=n; i++) {
		part[i][0] = true;
	}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=sum; j++) {
			if(j >= a[i-1]) {
				part[i][j] = part[i][j] || part[i-1][j-a[i-1]];
			}
			else {
				part[i][j] = part[i-1][j];
			}
		}
	}

	return part[n][sum];
}

