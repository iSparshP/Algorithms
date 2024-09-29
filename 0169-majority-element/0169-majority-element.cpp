class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto& itr:nums){
            mp[itr]++;
        }
        int majority=nums.size()/2;
        for(auto& it:mp){
            if(it.second>majority){
                return it.first;
            }
        }
        return -1;
    }
};