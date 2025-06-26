class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<bool>& isVisited){
        isVisited[node]=true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i]==1 && !isVisited[i]){
                dfs(i,isConnected,isVisited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> isVisited(n,false);
        for(int i=0;i<n;i++){
            if(!isVisited[i]){
                count++;
                dfs(i,isConnected,isVisited);
            }
        }
        return count;
    }
};