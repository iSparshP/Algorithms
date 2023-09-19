#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> vis;


void dfs(int node,int comp_no){
    vis[node]=comp_no;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,comp_no);
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
    
    int num_comp = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            num_comp++;
            dfs(i,num_comp);
        }
    }
    
    cout<<num_comp<<endl;
    
    for(int i=1;i<=n;i++){
        cout<<i<<": "<<vis[i]<<endl;
    }
}
