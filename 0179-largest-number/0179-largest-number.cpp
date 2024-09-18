class Solution {
public:
    static bool comp(string &a, string &b){
        return (a+b>b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string>s;
        for(int i=0;i<nums.size();i++){
            s.push_back(to_string(nums[i]));
        }
        string ans="";
        sort(s.begin(),s.end(),comp);
        for(auto it:s){
            ans+=it;
        }
        int i=0;
        while(i<ans.size()-1 and ans[i]=='0'){
            i++;
        }
        return ans.substr(i);
    }
};