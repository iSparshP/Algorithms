class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i:arr)mp[i]++;
        unordered_set<int>st;
        for(auto itr:mp){
            st.insert(itr.second);
        }
        return mp.size()==st.size();
    }
};