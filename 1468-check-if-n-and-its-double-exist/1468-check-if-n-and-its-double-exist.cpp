class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>st;
        for(int &i:arr){
            if(st.count(2*i)||(!(i&1) && (st.count(i/2))))
            {
                return true;
            }
            st.insert(i);
        }
        return false;
    }
};