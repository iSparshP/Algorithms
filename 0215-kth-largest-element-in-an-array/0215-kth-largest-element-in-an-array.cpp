class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>que;
        for(int i=0;i<nums.size();i++){
            que.push(nums[i]);
        }
        for(int i=0;i<k-1;i++){
            que.pop();
        }
        return que.top();
    }
};