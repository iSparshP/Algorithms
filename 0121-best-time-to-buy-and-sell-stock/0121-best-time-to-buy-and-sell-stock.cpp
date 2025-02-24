class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxPrice=0;
        for(auto & price:prices){
            minPrice=min(price,minPrice);
            maxPrice=max(maxPrice,price-minPrice);
        }
        return maxPrice;
    }
};