#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> vis;

bool is_cycle_present = false;

void dfs(int node,int par){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,node);
        }else if(v!=par)
            // cycle is presnet
            is_cycle_present = 1;
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
            dfs(i,0);
        }
    }
}
