class Solution {
public:
    // ((Memoization))
    // int solve(int level,vector<int>& nums,vector<int>&dp){
    //     //pruning
    //     if(level<0){
    //         return 0;
    //     }
    //     //base

    //     //cache
    //     if(dp[level]!=-1){
    //         return dp[level];
    //     }
    //     //save and compute
    //     int ans=1;
    //     for(int previous=0;previous<level;previous++){
    //         if(nums[previous]<nums[level]){
    //             ans=max(ans,1+solve(previous,nums,dp));
    //         }
    //     }
    //     //return 
    //     return dp[level]=ans;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        vector<int>dp(n,1);
        for(int level=1;level<n;level++){
            for(int previous=0;previous<level;previous++){
                if(nums[previous]<nums[level]){
                    dp[level]=max(dp[level],dp[previous]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};