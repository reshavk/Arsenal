/*-------------------------------------------------------------------
                            tenacious
-------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 7;
const int level = 20;

int parent[MAX][level];
int depth[MAX];
vector<int> adj[MAX];

//dfs to get the depth i.e. level of each node and find the first parent
//for each node
void dfs(int curr, int prev) {
    if(prev != -1)
        depth[curr] = depth[prev] + 1;
    parent[curr][0] = prev;
    for(int i=0; i<adj[curr].size(); i++) {
        if(adj[curr][i] != prev) {
            dfs(adj[curr][i], curr);
        }
    }
}

//square root decomposition method to store successive parents
void fillMatrix(int n) {
    for(int i=1; i<level; i++) {
        for(int node=0; node<n; node++) {
            if(parent[node][i-1] != -1) {
                parent[node][i] = parent[parent[node][i-1]][i-1];
            }
        }
    }
}

//lca algorithm
//first the node with higher level is made to climb up to reach same level
//then check if both have same parent or not
//until both have same parent both made to climb up proportionately
int lca(int a, int b) {
    if(depth[b] < depth[a])
        swap(b,a);

    int diff = depth[b] - depth[a];

    for(int i=0; i<level; i++) {
        if((diff>>i) & 1) {
            b = parent[b][i];
        }
    }

    if(a == b) {
        return a;
    }

    for(int i=level-1; i>=0; i--) {
        if(parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    memset(parent, -1, sizeof(parent));
    //total nodes in tree
    int n;
    cin >> n;


    int p;
    for(int i=1; i<=n-1; i++) {
        //parent of each node respectively from 1 to n-1;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    //number of nodes for which lowest common ancestor is to be found
    int m;
    cin >> m;

    int arr[m];
    for(int i=0; i<m; i++) {
        cin >> arr[i];
    }

    dfs(0,-1);
    fillMatrix(n);

    int x = lca(arr[0], arr[1]);
    for(int i=2; i<m; i++) {
        x = lca(x, arr[i]);
    }

    cout << x;
    return 0;

}
