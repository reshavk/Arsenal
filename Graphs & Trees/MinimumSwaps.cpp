/*
Given an unsorted array the problem is to find the minimum number of swaps required to get a sorted array.
*/

/*
Interestingly, this problem falls in the domain of a graph problem, what can be done is a directed edge can be
drawn from any element of the array to the index where the element actually belongs. This will prodeuce a
directed graph with disconnected cycles. Now for each disconnected cycle it can be observed that for each cycle 
mimimum of edge-1 swaps is necessary to get all the elements of that cycle at their original position.
*/

/*------------------------------------------------------------------------
                               tenacious
------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

int e = 0;
bool cycle = false;

void dfs(int s, vector<int> adj[], bool visited[], bool recstack[], int N) {
    if(!visited[s]) {
        visited[s] = true;
        recstack[s] = true;
        for(int i=0; i<adj[s].size(); i++) {
            if(!visited[adj[s][i]])  {
                e++;
                dfs(adj[s][i], adj, visited, recstack, N);
            }
            else if(recstack[adj[s][i]]) {
                e++;
                cycle = true;
            }
        }
    }
    recstack[s] = false;
}

int minSwaps(int A[], int N) {
    vector<int> adj[N];

    vector< pair<int, int> > v;
    for(int i=0; i<N; i++) {
        v.push_back({A[i], i});
    }

    sort(v.begin(), v.end());
    for(int i=0; i<N; i++) {
        adj[v[i].second].push_back(i);
    }

    int ans = 0;
    bool visited[N], recstack[N];
    memset(visited, false, sizeof(visited));
    memset(recstack, false, sizeof(recstack));
    for(int i=0; i<N; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited, recstack, N);
            if(cycle) {
                //cout << "Cycle";
                ans += e - 1;
                cycle = false;
                memset(recstack, false, sizeof(recstack));
                e  = 0;
            }
        }
    }

    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << minSwaps(arr, n);

    return 0;
}
