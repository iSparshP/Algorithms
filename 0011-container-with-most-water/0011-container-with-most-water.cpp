class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0;
        int high=height.size()-1;
        int ans=INT_MIN;
        while(low<high){
            int curr=min(height[low],height[high])*(high-low);
            ans=max(ans,curr);
            if(height[low]<height[high]){
                low++;
            }
            else{
                high--;
            }
        }
        return ans;
    }
};