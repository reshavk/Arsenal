/*
Detect cycle in a given directed graph
*/

/*
SOLUTION: 
A modified DFS is used. We perform a simple DFS and while travering we look for the existence of a backedge.
Backedge can be found by looking whether we have visited a node which has already been visited in the recursion stack,
i.e whose path is still being traversed.
*/
#include<bits/stdc++.h>
using namespace std;

bool cycle = false;

void dfs(int s, list<int> adj[], bool vis[], bool recstack[]) {
    if(!vis[s]) {
        vis[s] = true;
        recstack[s] = true;

        list<int>::iterator it;
        for(it=adj[s].begin(); it!=adj[s].end(); it++) {
            if(!vis[*it]) 
                dfs(*it, adj, vis, recstack);
            else if(recstack[*it])
                cycle = true;
        }
    }
    recstack[s] = false;
}


bool isCyclic(int V, list<int> adj[]) {
    //V no. of vertex
    //vector<int> adj[] : adjacency list
    cycle = false;

    bool vis[V];
    bool recstack[V];
    memset(vis, false, sizeof(vis));
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            memset(recstack, false, sizeof(recstack));
            dfs(i, adj, vis, recstack);
            if(cycle)
                return true;
        }
    }

    if(!cycle)
        return false;
}

/*
Detect cycle in a given undirected graph
*/

/*
SOLUTION : 
Finding cycle in an undirected graph is a bit less tedious and more easier for undirected graph. For directed graph
whenver a node was revisited it was necessary to enusre that it is on the same recursion stack to ensure the presence
of back edge as an edge could be aligned in any direction.
But in case of undirected graph, it is important to remember that since we can move freely bothways if a node is 
visited again then it must lead to formation of a cycle provided that node is not the parent of the previous node. 
*/
bool cycleU =  false;

void dfs(int s, list<int> adj[], bool vis[], int parent[]) {
    if(!vis[s]) {
        vis[s] = true;

        list<int>::iterator it;
        for(it=adj[s].begin(); it!=adj[s].end(); it++) {
            if(*it != s && parent[s] != *it) {
                parent[*it] = s;
            }
            if(!vis[*it])
                dfs(*it, adj, vis, parent);
            else if(*it != parent[s])
                cycle = true;
        }
    }
}


bool isCyclicU(int V, list<int> adj[]) {
    cycleU = false;
    bool visU[V];
    memset(visU, false, sizeof(false));
    int parent[V];
    memset(parent, -1, sizeof(parent));

    for(int i=0; i<V; i++) {
        if(!visU[i]) {
            dfs(i, adj, visU, parent);
        }
        if(cycle)
            return true;
    }
    if(!cycle)
        return false;
}

