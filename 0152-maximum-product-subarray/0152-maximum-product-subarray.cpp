class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int preSum=1;
        int posSum=1;
        int maxProd=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(preSum==0) preSum=1;
            if(posSum==0) posSum=1;
            preSum*=nums[i];
            posSum*=nums[n-i-1];
            maxProd=max(maxProd,max(preSum,posSum));
        }
        return maxProd;
    }
};