class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long bad=0;
        unordered_map<int, int> Count;
        for(int i=0;i<nums.size();i++){
            int diff=i-nums[i];
            int good=Count[diff];
            bad+=i-good;
            Count[diff]=good+1;
        }
        return bad;
    }
};