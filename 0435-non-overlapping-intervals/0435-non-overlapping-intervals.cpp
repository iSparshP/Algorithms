class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1]<b[1];
        });
        int end=INT_MIN;
        for(auto& interval:intervals){
            if(interval[0]>=end){
                end=interval[1];
            }
            else{
                count++;
            }
        }
        return count;

    }
};