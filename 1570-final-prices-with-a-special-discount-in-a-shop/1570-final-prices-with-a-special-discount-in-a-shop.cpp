class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans=prices;
        stack<int> st;
        for(int i=prices.size()-1;i>=0;i--){
            while(!st.empty() && st.top()>prices[i]) st.pop();
            ans[i] -= st.empty() ? 0:st.top();
            st.push(prices[i]);
        }
        return ans;
    }
};