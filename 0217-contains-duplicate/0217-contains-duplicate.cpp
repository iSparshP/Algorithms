class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int flag=0;
        for(auto &itr:mp){
            if(itr.second>=2){
                flag=1;
            }
        }
        return flag;
    }
};