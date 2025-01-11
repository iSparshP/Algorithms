class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k){
            return false;
        }
        vector<int>embed(26,0);
        for(int i=0;i<s.size();i++){
            embed[s[i]-'a']++;
        }
        int count=0;
        for(auto& it:embed){
            if(it%2!=0){
                count++;
            }
        }
        return count<=k;
    }
};