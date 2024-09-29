class Solution {
public:
    vector<vector<int>>v;
    void permute(vector<int>& nums, int low, int high){
        if(low==high){
            v.push_back(nums);
        }
        else{
            for(int i=low;i<high;i++){
                swap(nums[low],nums[i]);
                permute(nums,low+1,high);
                swap(nums[low],nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums,0,nums.size());
        return v;
    }
};