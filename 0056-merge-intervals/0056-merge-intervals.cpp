class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        if(i.empty()){
            return {};
        }
        sort(i.begin(),i.end());
        vector<vector<int>>res;
        for(auto& in:i){
            if(res.empty()|| res.back()[1]<in[0]){
                res.push_back(in);
            }
            else{
                res.back()[1]=max(res.back()[1],in[1]);
            }
        }
        return res;
    }
};