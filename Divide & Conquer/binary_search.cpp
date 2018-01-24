/*------------------------------------------------------------------------
                               tenacious
------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> a, int l, int r, int x) {
    int mid = (l+r)/2;
    if(mid == 0)
        return 0;
    if(mid > a.size())
        return -1;
    if(a[mid] >= x && a[mid-1] < x) {
        return mid;
    }
    else if(a[mid] >= x) {
        return lowerbound(a, l, mid, x);
    }
    else if (a[mid] < x) {
        return lowerbound(a, mid+1, r, x);
    }
}

int upperbound(vector<int> a, int l, int r, int x) {
    int mid = (l+r)/2;
    if(mid == 0) {
        return 0;
    }
    if(mid == a.size()-1){
        if(a[mid] < x)
            return -1;
        else
            return mid;
    }
    if(a[mid] <= x && a[mid + 1] > x ) {
        return mid;
    }
    else if(a[mid] <= x) {
        return upperbound(a, mid+1, r, x);
    }
    else if(a[mid] > x) {
        return upperbound(a, l, mid, x);
    }
}


int main() {
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int t;
    cin >> t;

    while(t--) {
        int x;
        cin >> x;

        cout << upperbound(a, 0, n-1, x) << "\n";
    }
    return 0;
}
