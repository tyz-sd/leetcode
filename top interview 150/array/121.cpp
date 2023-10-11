class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        int min_price = 0x7fffffff;
        int max_price = 0;
        for(int i = 0 ; i < length ; i++){
            min_price = min(min_price, prices[i]);
            max_price = max(max_price, prices[i] - min_price);
        }
        return max_price;
    }
};