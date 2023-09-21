#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> vis;

bool is_bipartite = true;

void dfs(int node,int color){
    vis[node]=color;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,3-color);
        }else if(vis[v]==vis[node]){
            is_bipartite = false;
        }
    }
}


int main(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vis.assign(n+1,0);
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,1);
        }
    }
    
    cout<<is_bipartite<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<": "<<vis[i]<<endl;
    }

    
}
