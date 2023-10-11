class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int length = prices.size();
        int max_profit[101][1001];
        int min_price[1001][1001];
        for(int i = 0 ; i < length ; i++){
            min_price[i][i] = prices[i];
            for(int j = i + 1 ; j < length ; j++){
                min_price[i][j] = min(min_price[i][j-1], prices[j]);
            }
        }
        for(int i = 0 ; i < length ; i++){
            for(int j = 0 ; j <= k ; j++){
                max_profit[j][i] = 0;
            }
        }
        for(int l = 1 ; l < length ; l++){
            for(int i = 1 ; i <= k ; i++){
                max_profit[i][l] = max_profit[i][l-1];
                for(int j = 0 ; j < l ; j++){
                    max_profit[i][l] = max(max_profit[i][l], max_profit[i-1][j] + prices[l] - min_price[j][l]);
                }
            }
        }
        return max_profit[k][length-1];
    }
};

// attempt1: n^2m attempt  1829ms && 25.46mb


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int length = prices.size();
        int max_profit[102][1001];
        int min_price[1001][1001];
        int sell[102][1001];
        for(int i = 0 ; i < length ; i++){
            for(int j = 0 ; j <= k ; j++){
                max_profit[j][i] = 0;
                sell[j][i] = 0;
            }
        }
        for(int i = 0 ; i < length ; i++){
            min_price[i][i] = prices[i];
            for(int j = i + 1 ; j < length ; j++){
                min_price[i][j] = min(min_price[i][j-1], prices[j]);
            }
        }
        for(int l = 1 ; l < length ; l++){
            if(prices[l-1] < prices[l]){
                for(int i = 1 ; i <= k ; i++){
                    if(sell[i][l-1] == l-1){ 
                        max_profit[i][l] = max_profit[i][l-1] + prices[l] - prices[l-1];
                        sell[i][l] = l;
                    }
                    else{
                        if(max_profit[i-1][l-1] + prices[l] - min_price[sell[i-1][l-1]][l-1] > max_profit[i][l-1]){
                            max_profit[i][l] = max_profit[i-1][l-1] + prices[l] - min_price[sell[i-1][l-1]][l-1];
                            sell[i][l] = l;
                        }
                        else {
                            max_profit[i][l] = max_profit[i][l-1];
                            sell[i][l] = sell[i][l-1];
                        }
                    }
                }
            }     
            else{
                for(int i = 1 ; i <= k ; i++){
                    max_profit[i][l] = max_profit[i][l-1];
                    sell[i][l] = sell[i][l-1];
                }
            }
        }
        return max_profit[k][length-1];
    }
};

//attempt2: wrong algorithm


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy(k+1, 0x7fffffff);
        vector<int> sell(k+1, 0);
        for(int i: prices)
            for(int j = 1 ; j <= k ; j++){
                buy[j] = min(i - sell[j-1], buy[j]);
                sell[j] = max(i - buy[j], sell[j]);
            }
        return sell[k];
    }
};

//attempt3: nb algorithm

