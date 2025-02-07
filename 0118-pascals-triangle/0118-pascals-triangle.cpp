class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int>pre;
        for(int i=0;i<numRows;i++){
            vector<int>curr(i+1,1);
            for(int j=1;j<i;j++){
                curr[j]=pre[j-1]+pre[j];
            }
            res.push_back(curr);
            pre=curr;
        }
        return res;
    }
};