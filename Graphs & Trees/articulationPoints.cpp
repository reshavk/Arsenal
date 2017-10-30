#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > adj(11);
int low[11];
int disc[11];
int parent[11];
int ap=0,b=0;
bool visited[11],AP[11];

vector< pair<int,int> > bri;

void APdfs(int v,int time){
    visited[v]=true;
    disc[v]=low[v]=time;
    int child=0;
    for(int i=0;i<adj[v].size();i++){
        int x = adj[v][i];
        child++;
        if(!visited[x]){
            parent[x]=v;
            APdfs(x,time+1);

            low[v]=min(low[v],low[x]);

            if(parent[v]==-1 && child > 1){
                AP[v]=true;
                ap++;
            }
            if(parent[v]!=-1 && low[x] >= disc[v]){
                AP[v]=true;
                ap++;
            }
        }
        else if(parent[v]!=x){
            low[v]=min(low[v],disc[x]);
        }
    }
}

void Bdfs(int v,int time){
    visited[v]=true;
    disc[v]=low[v]=time;
    for(int i=0;i<adj[v].size();i++){
        int x=adj[v][i];
        if(!visited[x]){
            parent[x]=v;
            Bdfs(x,time+1);

            low[v]=min(low[v],low[x]);

            if(low[x] > disc[v]){
                b++;
                bri.push_back(make_pair(min(x,v),max(x,v)));
            }
        }
        else if(parent[v]!=x){
            low[v]=min(low[v],disc[x]);
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    memset(parent,-1,sizeof(parent));
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    APdfs(0,0);
    cout<<ap<<"\n";
    for(int i=0;i<n;i++)
        if(AP[i])
            cout<<i<<" ";
    cout<<"\n";

    memset(parent,-1,sizeof(parent));
    memset(low,0,sizeof(low));
    memset(disc,0,sizeof(disc));
    memset(visited,false,sizeof(visited));

    Bdfs(0,0);
    cout<<bri.size()<<"\n";
    for(int i=bri.size()-1;i>=0;i--)
        cout<<bri[i].first<<" "<<bri[i].second<<"\n";

    return 0;

}
