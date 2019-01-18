/*
There are two parallel roads, each containing N and M buckets, respectively. 
Each bucket may contain some balls. The buckets in both roads are kept in such a way that they are sorted 
according to the number of balls in them.
The geek can change the road only at the point of intersection(which means , 
buckets with the same number of balls on two roads). Now you need to help Geek to collect the 
maximum number of balls.
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 7;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        int a[n], b[m];
        long long psa[n], psb[m];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        for(int i=0; i<m; i++) {
            cin >> b[i];
        }
        
        //sort(a, a+n);
        //sort(b, b+m);
        
        psa[0] = a[0];
        psb[0] = b[0];
        for(int i=1; i<n; i++) {
            psa[i] = psa[i-1] + a[i]; 
        }
        for(int i=1; i<m; i++) {
            psb[i] = psb[i-1] + b[i];
        }
        
        long long ps1 = 0, ps2 = 0, ans = 0;
        int i=0, j=0;
        while(true) {
            if(i == n || j == m) {
                ans += max(psa[n-1]-ps1, psb[m-1]-ps2);
                break;
            }
            if(a[i] > b[j]) {
                j++;
            }
            if(b[j] > a[i]) {
                i++;
            }
            if(a[i] == b[j]) {
                ans += max(psa[i] - ps1, psb[j] - ps2);
                ps1 = psa[i];
                ps2 = psb[j];
                i++;
                j++;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}