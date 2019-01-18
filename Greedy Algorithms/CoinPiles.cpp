/*
There are N piles of coins each containing  Ai (1<=i<=N) coins. 
Now, you have to adjust the number of coins in each pile such that for any two pile, 
if a be the number of coins in first pile and b is the number of coins in second pile then |a-b|<=K.
In order to do that you can remove coins from different piles to decrease the number of coins in 
those piles but you cannot increase the number of coins in a pile by adding more coins. 
Now, given a value of N and K, along with the sizes of the N different piles you have to tell the 
minimum number of coins to be removed in order to satisfy the given condition.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        long long ans = LONG_MAX;
        vector<int>::iterator it;
        int l, r;
        long long temp;
        for(int i=0; i<n; i++) {
            temp = 0;
            for(int j=0; j<n; j++) {
                if(a[j] < a[i]) {
                    temp += a[j];
                }
                else if(a[j] > a[i]+k){
                    temp += a[j] - a[i] - k;
                }
            }
            //cout << temp << " ";
            ans = min(ans, temp);
        }
        
        cout << ans << "\n";
    }
    return 0;
}

// O(n^2) approach , just look for all possible ways to perform the same.