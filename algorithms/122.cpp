class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        for(int i = length - 2; i >= 0 ; i--){
            if(prices[i] >= prices[i+1]) length--;
            else break;
        }
        vector<int> min_price(length * length);
        vector<int> max_price(length);
        int max_price_in_total = 0;
        for(int i = 0 ; i < length ; i ++){
            int min_price_tmp = prices[i];
            min_price[i * length + i] = prices[i];
            max_price[i] = 0;
            for(int j = i + 1 ; j < length ; j ++){
                min_price_tmp = min(min_price_tmp, prices[j]);
                min_price[i * length + j] = min_price_tmp;
            }
        }
        for(int i = 0 ; i < length ; i++){
            for(int j = 0 ; j <= i ; j++){
                max_price[i] = max(max_price[i], max_price[j] + prices[i] - min_price[j * length + i]);
                max_price_in_total = max(max_price_in_total, max_price[i]);
            }
        }
        return max_price_in_total;
    }
};

//attempt1: n^2 DP : 2432ms and 411MB : too long and memory consuming

