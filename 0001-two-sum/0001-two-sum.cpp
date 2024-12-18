class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int com=target-nums[i];
            if(mp.find(com)!=mp.end()){
                return vector<int>{mp[com],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};