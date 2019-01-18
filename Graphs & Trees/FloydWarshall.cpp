/*
Floyd Warshall algorithm is a DP algorithm used for finding each pair shortest path in a graph.
Floyd Warshall algorithm assumes that there are no negative cycles in the graph.
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3+7;

//O(n^3) Solution

void floydWarshall(int n, int adj[MAX][MAX]) {
    //select each node as an intermediate node while going through that intermediate node if distance traversed is
    //less than the distance between source and destination update it.
    //we keep on adding nodes into the intermediate nodes set hence checking solution for each possible combination
    //of intermediate nodes.
    for(int k=0; k<n; k++) {
        //select each node as source
        for(int i=0; i<n; i++) {
            //select each node as destination
            for(int j=0; j<n; j++) {
                if(adj[i][k] + adj[k][j] < adj[i][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }
}