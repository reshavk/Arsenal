


/*-------------------------------------------------------------------
                            tenacious
-------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 17;
vector< vector<int> > adj(MAX), radj(MAX);
bool visited[MAX] = {};

void dfs(int v){
    if(!visited[v]){
        visited[v] = true;
        for(int i=0; i<adj[v].size(); i++){
            if(!visited[adj[v][i]])
                dfs(adj[v][i]);
        }
    }
}

stack<int> s;
int o = 0, e = 0;
int c = 0;
void scc(int src){

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a, b;

    for(int i=0; i<m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }



}
