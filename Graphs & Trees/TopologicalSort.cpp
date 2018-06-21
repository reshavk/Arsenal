/*
Topological sorting is performed for directed graphs. TS of a graph refers to the sorted order of vertices in 
which a vertex is visited only after all the vertex pointing to that vertex have been visited i.e. indegree 
of vertex has become zero.
*/
#include<bits/stdc++.h>
using namespace std;

// O(n^2) Solution
int * topoSort(vector<int> graph[], int N) {

   int indegree[N] = {};
   bool visited[N] = {};
   for(int i=0; i<N; i++) {
       for(int j=0; j<graph[i].size(); j++) {
           indegree[graph[i][j]]++;
       }
   }
   
   queue<int> q;
   for(int i=0; i<N; i++) {
       if(!visited[i] && indegree[i] == 0) {
           q.push(i);
           visited[i] = true;
       }
   }
   
   int *topsort = new int[N];
   int i=0, v;
   while(!q.empty()) {
       v = q.front();
       topsort[i++] = v;
       q.pop();
       for(int i=0; i<graph[v].size(); i++) {
           indegree[graph[v][i]]--;
       }
       
       for(int i=0; i<N; i++) {
           if(!visited[i] && indegree[i] == 0) {
                q.push(i);
                visited[i] = true;
           }
       }
   }
   
   return topsort;
}