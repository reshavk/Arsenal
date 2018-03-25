//Given a stream of input charachters at each input we have to return the first charachter which hasn't yet been repeated in the stream

//Queue based approach 
//Time complexity : O(n^2) in worst case

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        char temp;
        queue<char> q;
        
        int h[26] = {};
        for(int i=0; i<n; i++) {
            cin >> temp;
            q.push(temp);
            h[temp-'a']++;
            
            while(!q.empty() && h[q.front()-'a'] > 1) {
                q.pop();
            }
            
            if(!q.empty())
                cout << q.front() << " ";
            else
                cout << -1 << " ";
        }
        cout << "\n";
    }
    return 0;
}

//There does exists another DLL based approach to solve the same in O(1) time complexity.
//Link https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0
