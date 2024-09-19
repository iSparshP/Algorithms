class Solution {
private:
    int arr[26]={0};
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            int n=s[i]-'a';
            arr[n]++;
        }
        for(int i=0;i<t.size();i++){
            int n=t[i]-'a';
            arr[n]--;
        }
        for(auto itr:arr){
            if(itr!=0){
                return false;
            }
        }
        return true;
    }
};