class Solution {
public:
    int _gcd(int a, int b){
        if(b==0){
            return a;
        }
        return _gcd(b,a%b);
    }
    string gcdOfStrings(string str1, string str2) {
        int num=_gcd(str1.length(),str2.length());
        if(str1+str2==str2+str1){
            return str1.substr(0,num);
        }
        return "";
    }
};