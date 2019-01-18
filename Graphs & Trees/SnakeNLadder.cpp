/*
Given a snake and ladder board of order 5x6 , find the minimum number of dice throws required to reach the 
destination or last cell (30th cell) from source (1st cell) . 
*/

//Solution using Dijkstra
/*
First of all add the edges denoted by snake or ladder using an edge of weight 0.
Simply build a directed graph in which you can reach to any node within the range of +6 to a node and the weight
of this edge should be equal to 1.
After the directed graph is build just run a dijkstra algorithm with source 1 and the dist[30] is our solution.
*/

/*-----------------------------------------------------------------------
                               tenacious
------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 37;

void dijkstra(vector< pair<int, int> > adj[]) {
    int dist[MAX];
    for(int i=0; i<MAX; i++) {
        dist[i] = MAX;
    }
        
    dist[1] = 0;     
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push({0, 1});
    
    int v, d;
    while(!pq.empty()) {
        v = pq.top().second;
        d = pq.top().first;
        pq.pop();
        for(int i=0; i<adj[v].size(); i++) {
            if(dist[adj[v][i].first] > d+adj[v][i].second) {
                dist[adj[v][i].first] = d+adj[v][i].second;
                pq.push({d+adj[v][i].second, adj[v][i].first});
            }
        }
    }
    
    cout << dist[30] << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        int a, b;
        vector< pair<int, int> > adj[MAX];
        for(int i=0; i<n; i++) {
            cin >> a >> b;
            adj[a].push_back({b, 0});
        }
        
        for(int i=1; i<=30; i++) {
            for(int j=1; j<=6 && (i+j) <= 30; j++) {
                adj[i].push_back({i+j, 1});
            }
        }
        
        /*for(int i=1; i<=30; i++) {
            cout << i << "->";
            for(int j=0; j<adj[i].size(); j++) {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }*/
        
        dijkstra(adj);
    }
    return 0;
}
