/*-------------------------------------------------------------------
                            tenacious
-------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 11;
bool visited[MAX] = {};
int parent[MAX], low[MAX], disc[MAX];
vector< vector<int> > adj(11);
stack< pair<int, int> > s;

int o = 0, e = 0;

void bcdfs(int u, int time){
    visited[u] = true;
    disc[u] = low[u] = time;
    int child = 0;
    int v;
    for(int i=0; i<adj[u].size(); i++){
        v = adj[u][i];
        child++;
        if(!visited[v]){
            parent[v] = u;
            s.push(make_pair(u,v));
            bcdfs(v, time+1);

            low[u] = min(low[u], low[v]);
            if(parent[u] == -1 && child > 1){
                int hash[11] = {};
                pair<int, int> p = make_pair(u, v), q;
                int cnt = 0;
                while(s.top() != p){
                    q = s.top();
                    if(hash[q.first] == 0)
                        cnt++;
                    if(hash[q.second] == 0)
                        cnt++;
                    hash[q.first] = hash[q.second] = 1;
                    s.pop();
                }
                q = s.top();
                if(hash[q.first] == 0)
                    cnt++;
                if(hash[q.second] == 0)
                    cnt++;
                hash[q.first] = hash[q.second] = 1;
                if(cnt%2)
                    o++;
                else
                    e++;
                s.pop();
            }
            if(parent[u] != -1 && low[v] >= disc[u]){
                int hash[11] = {};
                pair<int, int> p = make_pair(u, v), q;
                int cnt = 0;
                while(s.top() != p){
                    q = s.top();
                    if(hash[q.first] == 0)
                        cnt++;
                    if(hash[q.second] == 0)
                        cnt++;
                    hash[q.first] = hash[q.second] = 1;
                    s.pop();
                }
                q = s.top();
                if(hash[q.first] == 0)
                    cnt++;
                if(hash[q.second] == 0)
                    cnt++;
                hash[q.first] = hash[q.second] = 1;
                if(cnt%2)
                    o++;
                else
                    e++;
                s.pop();
            }
        }
        else if(parent[u] != v && disc[v] < low[u]){
            low[u] = disc[v];
            s.push(make_pair(u,v));
        }
    }
}

void biconnectedComponents(int n){
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bcdfs(i, 0);
            if(!s.empty()){
                int hash[11] = {};
                pair<int, int> q;
                int cnt = 0;
                while(!s.empty()){
                    q = s.top();
                    if(hash[q.first] == 0)
                        cnt++;
                    if(hash[q.second] == 0)
                        cnt++;
                    hash[q.first] = hash[q.second] = 1;
                    s.pop();
                }
                if(cnt%2)
                    o++;
                else
                    e++;
            }
        }
    }
    cout << o << " " << e << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    memset(parent,-1,sizeof(parent));
    int n, m;
    cin >> n >> m;

    int x, y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    biconnectedComponents(n);


}
