class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string str=to_string(x);
        int low=0;
        int high=str.length()-1;
        while(low<high){
            if(str[low]!=str[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};