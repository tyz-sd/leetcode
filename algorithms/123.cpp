class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = 0x7fffffff;
        int max_price = 0;
        int length = prices.size();
        vector<int> max_pro_once(length);
        vector<int> max_pro_twice(length);
        for(int i = 0 ; i < length ; i++){
            min_price = min(min_price, prices[i]);
            max_pro_once[i] = max(max_profit, prices[i] - min_price);
            max_profit = max_pro_once[i];
        }   
        max_profit = 0;
        for(int i = length - 1 ; i >= 0 ; i--){
            max_price = max(max_price, prices[i]);
            max_pro_twice[i] = max(max_profit, max_price - prices[i]);
            max_profit = max_pro_twice[i];
        }   
        max_profit = 0;
        for(int i = 0 ; i < length - 1 ; i++){
            max_profit = max(max_profit, max_pro_once[i] + max_pro_twice[i]);
        }
        return max_profit;
    }
};

//attempt 1: On On 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = 0x7fffffff, buy2 = 0x7fffffff;
        int sell1 = 0, sell2 = 0;
        for(int i: prices){
            buy1 = min(buy1, i);
            sell1 = max(sell1, i - buy1);
            buy2 = min(buy2, i - sell1);
            sell2 = max(sell2, i - buy2);
        }
        return sell2;
    }
};

//attempt2: use On O1