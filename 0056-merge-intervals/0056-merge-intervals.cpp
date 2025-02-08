class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return {};
        }
        sort(intervals.begin(),intervals.end(), [](const vector<int>&a, const vector<int>&b)
        {
            return a[0]<b[0];
        });
        vector<vector<int>>merged;
        merged.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int>& lastMerged=merged.back();
            vector<int>& curr=intervals[i];
            if(curr[0]<=lastMerged[1]){
                lastMerged[1]=max(lastMerged[1],curr[1]);
            }
            else{
                merged.push_back(curr);
            }
        }
        return merged;
    }
};