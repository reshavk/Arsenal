//Rearrange charachters of a string in such a way that no two adjacent charachters are same, print Not Valid String
//if not possible
#include<bits/stdc++.h>
using namespace std;

struct key {
    int freq;
    char x;

    bool operator < (const key &k) const {
        return freq < k.freq;
    }
};


void rearrangeCharachters(string s) {
    priority_queue<key> pq;

    int h[26] = {};
    for(int i=0; i<s.size(); i++) {
        h[s[i]-'a']++;
    }

    for(int i=0; i<26; i++) {
        if(h[i]) {
            pq.push(key {h[i], 'a'+i});
        }
    }

    string ans = "";
    key prev = {-1, '#'};

    key k;
    while(!pq.empty()) {
        k = pq.top();
        pq.pop();

        ans += k.x;
        k.freq--;

        if(prev.freq > 0)
            pq.push(prev);
        
        prev = k;
    }

    if(s.size() != ans.size()) {
        cout << "Not valid String";
    }
    else
        cout << ans << "\n";

}