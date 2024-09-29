class Solution {
public:
    int cs(vector<int>& coins, int amount,vector<int>&dp){
        //pruning
        if(amount<0){
            return INT_MAX;
        }

        //base
        if(amount==0){
            return 0;
        }

        //cache
        if(dp[amount]!=-1){
            return dp[amount];
        }

        //save and compute
        int ans=INT_MAX;
        for(auto coin:coins){
            int res = cs(coins,amount-coin,dp);
            if(res!=INT_MAX){
                ans=min(ans,res+1);
            }
        }

        //return
        dp[amount]=ans;
        return dp[amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int result= cs(coins, amount, dp);
        return result==INT_MAX?-1:result;
    }
};