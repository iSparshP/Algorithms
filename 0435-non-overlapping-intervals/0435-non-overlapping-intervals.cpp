class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())return 0;
        int count=0;
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){return a[1]<b[1];});
        int curr_end=INT_MIN;
        for(const auto& interval:intervals){
            if(interval[0]>=curr_end){
                count++;
                curr_end=interval[1];
            }
        }
        return intervals.size()-count;
    }
};