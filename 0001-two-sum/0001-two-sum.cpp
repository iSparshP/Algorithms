class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>unMap;
        for(int i=0;i<n;i++)
        {
            int comp=target-nums[i];
            if(unMap.find(comp)!=unMap.end())
            {
                return vector<int>{unMap[comp],i};
            }
            unMap[nums[i]]=i;
        }
        return {};
    }
};