class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        int max_profit = 0;
        int cur_holding = prices[0];
        for(int i = 0 ; i < length - 1 ; i ++){
            if(prices[i] < prices[i+1]) continue;
            if(prices[i] >= prices[i+1]) {
                max_profit += prices[i] - cur_holding;
                cur_holding = prices[i+1];
            }
        }
        max_profit += prices[length - 1] - cur_holding;
        return max_profit;
    }
};