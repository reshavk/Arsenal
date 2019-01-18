//Given an array, for each element print the next greater element in the array. If doesn't exist print -1.'

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        stack<int> s;
        
        int a[n], ans[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        
        for(int i=n-1; i>=0; i--) {
            if(s.empty()) {
                ans[i] = -1;
                s.push(a[i]);
            }
            else {
                if(a[i] >= s.top()) {
                    while(!s.empty() && a[i] >= s.top())
                        s.pop();
                    if(!s.empty())
                        ans[i] = s.top();
                    else
                        ans[i] = -1;
                    s.push(a[i]);
                }
                else {
                    ans[i] = s.top();
                    s.push(a[i]);
                }
            }
        }
        
        for(int i=0; i<n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}
