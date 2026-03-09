class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_to_index_map;

        for (int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];
            
            if (nums_to_index_map.count(compliment)) {
                return {nums_to_index_map[compliment], i};
            }

            nums_to_index_map[nums[i]] = i;
        }
        
        return {};
    }
};