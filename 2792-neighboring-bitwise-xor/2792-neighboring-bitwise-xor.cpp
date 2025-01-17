class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR = 0;
        for(auto ele:derived){
            XOR = XOR^ele;
        }
        return XOR == 0;
    }
};