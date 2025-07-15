class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j){
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]='0';
        vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto &dir:directions){
                int _x = x+dir.first;
                int _y = y+dir.second;
                if(_x>=0 && _x<row && _y>=0 && _y<col && grid[_x][_y]=='1'){
                    grid[_x][_y]='0';
                    q.push({_x,_y});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    bfs(grid,i,j);
                }
            }
        }
        return count;
    }
};