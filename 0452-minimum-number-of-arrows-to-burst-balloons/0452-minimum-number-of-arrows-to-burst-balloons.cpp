class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b){return a[1]<b[1];});
        int arrows=1;
        int curr_end=points[0][1];
        for(const auto& ballon: points){
            if(ballon[0]>curr_end){
                arrows++;
                curr_end=ballon[1];
            }
        }
        return arrows;
    }
};