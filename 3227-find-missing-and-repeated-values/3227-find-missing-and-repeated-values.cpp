class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans={0,0};
        unordered_map<int,int> map;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                map[grid[i][j]]++;
            }
        }
        int size=grid.size()*grid.size()+1;
        for(int i=1;i<size;i++){
            if(map[i]==2){
                ans[0]=i;
            }
            else if(map[i]==0){
                ans[1]=i;
            }
        }
        return ans;
    }
};