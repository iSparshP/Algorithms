class Solution {
public:
    bool check(int mid, vector<int>& nums) {
        if (mid == 0 || nums[mid] > nums[mid - 1]) {
            return true;
        }
        return false;
    }

    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int peak = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, nums)) {
                peak = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return peak;
    }
};