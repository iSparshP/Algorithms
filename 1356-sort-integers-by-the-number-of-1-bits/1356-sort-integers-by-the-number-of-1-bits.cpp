class Solution {
public:
    unordered_map<int,int> memo;

    int bitMapper(int num) {
        if (memo.count(num)) return memo[num];
        return memo[num] = __builtin_popcount(num);
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int bitsA = bitMapper(a);
            int bitsB = bitMapper(b);
            
            if (bitsA == bitsB)
                return a < b;
            
            return bitsA < bitsB;
        });
        
        return arr;
    }
};