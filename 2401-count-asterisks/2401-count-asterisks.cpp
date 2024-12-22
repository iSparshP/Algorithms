class Solution {
public:
    int countAsterisks(string s) {
        int n=s.length();
        int ans=0;
        bool bar=false;
        for(int i=0;i<n;i++){
            if(s[i]=='|'){
                bar=!bar;
            }
            else if(s[i]=='*'&&!bar){
                ans++;
            }
        }
        return ans;
    }
};