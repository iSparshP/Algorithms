class Solution {
public:
    int dfs(vector<vector<int>> &adj,vector<bool>&visited, int from){
        auto change=0;
        visited[from]=true;
        for(auto to:adj[from]){
            if(!visited[abs(to)]){
                change += dfs(adj, visited, abs(to)) + (to>0);
            }
        }
        return change;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &city: connections){
            adj[city[0]].push_back(city[1]);
            adj[city[1]].push_back(-city[0]);
        }
        return dfs(adj,vector<bool>(n)={},0);
    }
};