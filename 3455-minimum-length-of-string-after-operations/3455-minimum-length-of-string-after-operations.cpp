class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        for(auto &it:s){
            freq[it - 'a']++;
        }
        int ans=0;
        bool isPossible=true;
        for(auto &itr:freq){
            if(itr){
                ans += 1 + (itr %2==0);
            }
        }
        return ans;
    }
};