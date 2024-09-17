class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        int low=0;
        int high=n-1;
        long long ans=0;
        int count=0;
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        while(count<k){
            while(pq1.size()<candidates && low<=high) pq1.push(costs[low++]);
            while(pq2.size()<candidates && high>=low) pq2.push(costs[high--]);
            int a=pq1.size()> 0? pq1.top() : INT_MAX;
            int b=pq2.size()> 0? pq2.top() : INT_MAX;
            if(a<=b){
                ans+=a;
                pq1.pop();
            }
            else{
                ans+=b;
                pq2.pop();
            }
            count++;
        }
        return ans;
    }
};