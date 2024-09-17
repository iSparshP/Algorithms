class Solution {
public:
    static bool comp(const pair<int,int>&a, const pair<int,int>&b){
        return a.second<b.second;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>pairs;
        for(int i=0;i<nums1.size();i++){
            pairs.push_back({nums1[i],nums2[i]});
        }
        sort(pairs.begin(),pairs.end(),comp);
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        long long max_sum=0;
        int n=nums1.size();
        for(int i=n-1;i>=0;i--){
            int minvalue=pairs[i].second;
            while(pq.size()>k-1){
                sum-=pq.top();
                pq.pop();
            }
            sum+=pairs[i].first;
            pq.push(pairs[i].first);
            if(pq.size()==k){
                max_sum=max(max_sum,sum*minvalue);
            }
        }
        return max_sum;
    }
};