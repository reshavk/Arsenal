/*
Obtain the maximum subarray sum for an array and rank them on the basis of kth maximum
Given 3 numbers k1, k2, k3 return the value of the sum k1th maximum subarray sum, k2th maximum subarray sum
ans k3th maximum subarray sum.
*/

//O(n * (nlog(k3)) ) : Using priority queue
/*------------------------------------------------------------------------
                               tenacious
------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        int k1, k2, k3;
        cin >> k1 >> k2 >> k3;

        int arr[n];
        int ps[n+1];
        ps[0] = 0;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            ps[i+1] = ps[i] + arr[i];
        }


        priority_queue<int, vector<int>, greater<int> > pq;
        int temp, k;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<i; j++) {
                temp = ps[i] - ps[j];
                if(pq.size() < k3)
                    pq.push(temp);
                else {
                    if(pq.top() < temp) {
                        pq.pop();
                        pq.push(temp);
                    }
                }
                if(pq.size() > k3) {
                    pq.pop();
                }
            }
        }

        //cout << pq.size();

        int i=0;
        vector<int> v(k3+1);
        i = k3;
        while(!pq.empty()) {
            v[i--] = pq.top();
            pq.pop();
        }
        cout << v[k1] << " " << v[k2] << " " << v[k3] << "\n";
    }
    return 0;
}

//O(n * (n + k3)) : Using merge operation
/*
In this solution we would obtain a vector of k3 size for each i, and we want this vector to be sorted for this we
will do insertion sort on each step. After obtaining the vector of size k we would merge that vector with a 
previously maintained solution vector of size k3 so that we have a overall solution vector with us.
*/
