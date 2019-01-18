/*------------------------------------------------------------------------
                               tenacious
------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
int bsize;
const int MAX = 1e6+7;

struct query {
    int l, r;
};

bool cmp(query a, query b) {
    if(a.l/bsize < b.l/bsize)
        return true;
    else if(a.l/bsize > b.l/bsize)
        return false;
    else {
        if(a.r < b.r)
            return true;
        else
            return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    bsize = sqrt(n);

    int a[n+1];
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    vector<query> v, x;
    query Q;
    for(int i=0; i<q; i++) {
        cin >> Q.l >> Q.r;
        v.push_back(Q);
        x.push_back(Q);

    }

    sort(v.begin(), v.end(), cmp);

    int h[MAX] = {}, c = 1, s = 1, e = 1;
    h[a[s]]++;
    map< pair<int, int>, int > m;
    for(int i=0; i<v.size(); i++) {
        while(!(s == v[i].l && e == v[i].r)) {
            if(s < v[i].l) {
                h[a[s]]--;
                if(h[a[s]] == 0)
                    c--;
                s++;
            }
            else if(s > v[i].l) {
                s--;
                h[a[s]]++;
                if(h[a[s]] == 1)
                    c++;
            }
            if(e < v[i].r) {
                e++;
                h[a[e]]++;
                if(h[a[e]] == 1)
                    c++;
            }
            else if(e > v[i].r) {
                h[a[e]]--;
                if(h[a[e]] == 0)
                    c--;
                e--;
            }
        }
        m[{v[i].l, v[i].r}] = c;
    }

    for(int i=0; i<x.size(); i++) {
        cout << m[{x[i].l, x[i].r}] << "\n";
    }
    return 0;
}

