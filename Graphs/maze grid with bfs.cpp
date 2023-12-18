#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
const int INF = 100;
/*
6 6
S . # . . .
. . # . . .
# . # . # . 
. . . . # .
# # # # . .
F . . . . .
*/

int n,m;
vector<vector<char>> arr;
using state = pair<int,int>;

bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&arr[x][y]!='#'){
        return 1;
    }
    return 0;
}

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

// int dx[]={2,1,-1,-2,-2,-1,1,2};
// int dy[]={-1,-2,-2,-1,1,2,2,1};

vector<state> neigbours(state node){
    vector<state> neighs;
    for(int k=0;k<4;k++){
        int x = node.F + dx[k];
        int y = node.S + dy[k];
        if(is_valid(x,y)){
            neighs.push_back({x,y});
        }
    }
    return neighs;
}

vector<vector<int>> dis;
vector<vector<int>> num_path;
vector<vector<state>> par;

void bfs(state st_node){
    dis.assign(n,vector<int>(m,INF));
    num_path.assign(n,vector<int>(m,0));
    par.assign(n,vector<state>(m,{-1,-1}));
    
    queue<state> q;
    dis[st_node.F][st_node.S] = 0;
    num_path[st_node.F][st_node.S] = 1;
    par[st_node.F][st_node.S] = {-1,-1};
    q.push(st_node);
    
    while(!q.empty()){
        state node = q.front();
        q.pop();
        for(state v:neigbours(node)){
            if(dis[v.F][v.S]==INF){
                dis[v.F][v.S] = dis[node.F][node.S]+1;
                num_path[v.F][v.S] = num_path[node.F][node.S];
                par[v.F][v.S] = node;
                q.push(v);
            }else if(dis[v.F][v.S]==dis[node.F][node.S]+1){
                num_path[v.F][v.S] += num_path[node.F][node.S];
            }
        }
    }
}

void print_path(state en){
    vector<state> path;
        
    state cur = en;
    while(cur!=make_pair(-1,-1)){
        path.push_back(cur);
        cur = par[cur.F][cur.S];
    }
    reverse(path.begin(),path.end());
    
    for(auto v:path){
        cout<<v.F<<" "<<v.S<<endl;
    }
}

int main(){
    cin>>n>>m;
    arr.resize(n);
    
    state st,en;
     
    for(int i=0;i<n;i++){
        arr[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='S'){
                st = {i,j};
            }else if(arr[i][j]=='F'){
                en = {i,j};
            }
        }
    }
    
    bfs(st);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dis[i][j]<<","<<num_path[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    if(dis[en.F][en.S]==INF){
        cout<<"Finish is not reachable\n";
    }else{
        cout<<dis[en.F][en.S]<<endl;
        print_path(en);
    }
}
