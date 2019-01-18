/*
Dijkstra algorithm is used for finding single source shortest path to various vertices.
*/
#include<bits/stdc++.h>
using namespace std;

// O(n^2) Solution using adjacency matrix
const int INF = 1e7+7;
const int MAX = 1e3+7;

void dijkstra(int graph[MAX][MAX], int s,int V) {
   //Your code here
   int dist[V];
   for(int i=0; i<V; i++) {
       dist[i] = INF;
   }
   dist[s] = 0;
   
   bool visited[V];
   memset(visited, false, sizeof(visited));
   
   int d = 0;
   for(int i=0; i<V; i++) {
       visited[s] = true;
       for(int j=0; j<V; j++) {
           if(graph[s][j] != 0) {
               if(dist[j] > d + graph[s][j]) {
                   dist[j] = d + graph[s][j];
               }
           }
       }
       
       d = INF;
       for(int j=0; j<V; j++) {
           if(!visited[j] && dist[j] < d) {
               d = dist[j];
               s = j;
           }
       }
   }
   
   for(int i=0; i<V; i++) {
       cout << dist[i] << " ";
   }
}

// O(ElogV) Optimal Soution using priority queue
void dijkstra(int graph[MAX][MAX], int s, int V) {
    int dist[V];
    for(int i=0; i<V; i++)
        dist[i] = INF;
    dist[s] = 0;
    
    bool visited[V];
    memset(visited, false, sizeof(visited));

    priority_queue< pair<int, int> , vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push({dist[s],s});

    int d = 0; 
    while(!pq.empty()) {

        s = pq.top().second;
        d = pq.top().first;
        pq.pop();

        for(int j=0; j<V; j++) {
            if(graph[s][j] != 0) {
                if(dist[j] > d + graph[s][j]) {
                    dist[j] = d + graph[s][j];
                    
                    pq.push({dist[j], j});
                }
            }
        }
    }

    for(int i=0; i<V; i++) {
        cout << dist[i] << " ";
    }
}
