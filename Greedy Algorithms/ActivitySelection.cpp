// Problem : Given N activities with their start and finish times. Select the maximum number of activities 
//			 that can be performed by a single person, 
//			 assuming that a person can only work on a single activity at a time.

#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4+7;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        int s[n], e[n];
        for(int i=0; i<n; i++)
            cin >> s[i];
        for(int i=0; i<n; i++) 
            cin >> e[i];
            
        vector< pair<int,int> > v;
        for(int i=0; i<n; i++) {
            v.push_back(make_pair(e[i], s[i]));
        }
        
        sort(v.begin(), v.end());
        
        int ans = 0, p = 0;
        for(int i=0; i<n; i++) {
            if(v[i].second >= p) {
                ans++;
                p = v[i].first;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}

// Make pair of ending time and starting time of activities. Sort according to ending times,
// decide on the basis of starting time if aa task can be executed or not. 