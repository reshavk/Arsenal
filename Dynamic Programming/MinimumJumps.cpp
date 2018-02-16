//Aim is to find out the minimum no. of jumps required to reach from starting index = 0 to last index of the array;
//Given is the maximum jump that can be made from each index

//O(n^2) solution using DP
int n;
cin >> n;

const int INF = 1e5 + 7;

int a[n], dp[n];
for(int i=0; i<n; i++) {
	cin >> a[i];
	dp[i] = INF;
}

for(int i=0; i<n; i++) {
	for(int j=i+1; j<min(i+a[i], n); j++) {
		dp[j] = min(dp[i]+1, dp[j]);
	}
} 

if(dp[n-1] != INF)
	cout << dp[n-1];
else
	cout << -1; //destination is unreachable

//O(n) solution again using DP
int n;
cin >> n;

int a[n];
for(int i=0; i<n; i++)
	cin >> a[i];

if(n <= 1)
	cout << 0 << "\n";

if(a[i] == 0)
	cout << -1 << "\n";

int maxreach = 0+a[0];
int steps = a[0];
int jumps = 1;

for(int i=1; i<n; i++) {
	if(i == n-1)
		return jump;

	steps--;
	maxreach = max(maxreach, i + a[i]);

	if(steps == 0) {
		jump++;
		if(i >= maxreach) {
			cout << -1 << "\n";
		}
		else {
			steps = maxreach - i;
		}
	}
}

cout << -1 << "\n";
