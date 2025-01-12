class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()&1){
            return false;
        }
        return check(s,locked,true) && check(s,locked,false);
    }
private:
    bool check(string& s, string& locked, bool isForward){
        int changeable=0;
        int left=0;
        int right=0;
        
        int start = isForward ? 0 : s.length() - 1;
        int end = isForward ? s.length() : -1;
        int step = isForward ? 1 : -1;

        for (int i = start; i != end; i += step) {
            if (locked[i] == '0') {
                changeable += 1;
            } else if (s[i] == '(') {
                left += 1;
            } else {  
                right += 1;
            }

            if (isForward && changeable + left - right < 0) { 
                return false;
            }
            if (!isForward && changeable + right - left < 0) { 
                return false;
            }
        }

        return true;
    }
};