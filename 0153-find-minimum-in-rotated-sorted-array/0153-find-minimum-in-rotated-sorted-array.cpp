class Solution {
public:
    bool check(int mid,vector<int>& nums){
        if(nums[0]>nums[mid]){
            return true;
        }
        return false;
    }
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=low;
        if(nums[low]<nums[high]){
            return nums[low];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,nums)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return nums[ans];
    }
};