class Solution {
public:
    int candy(vector<int>& ratings) {
        int length = ratings.size();
        vector<int> candies(length);
        int down_first = 0;
        if(length == 1){return 1;}
        for(int i = 0 ; i < length ; i++){
            if(i == 0){
                if(ratings[i] <= ratings[i+1]){
                    candies[i] = 1;
                    down_first = -1;
                }
                else{
                    down_first = i;
                }
            }
            else if(i == length-1){
                if(ratings[i] < ratings[i-1]){
                    candies[i] = 1;
                    for(int j = i - 1 ; j >= down_first ; j--){
                        candies[j] = candies[j+1] + 1;
                    }
                    if(down_first != 0 && ratings[down_first] > ratings[down_first-1])
                        candies[down_first] = max(candies[down_first], candies[down_first-1] + 1);
                }
                else if(ratings[i] > ratings[i-1]){
                    candies[i] = candies[i-1] + 1;
                }
                else{
                    candies[i] = 1;
                }
            }
            else{
                if(ratings[i] < ratings[i-1] && ratings[i] <= ratings[i+1]){
                    candies[i] = 1;
                    for(int j = i - 1 ; j >= down_first ; j--){
                        candies[j] = candies[j+1] + 1;
                    }
                    if(down_first != 0 && ratings[down_first] > ratings[down_first-1])
                        candies[down_first] = max(candies[down_first], candies[down_first-1] + 1);
                }
                else if(ratings[i] > ratings[i-1] && ratings[i] <= ratings[i+1]){
                    candies[i] = candies[i-1] + 1;
                }
                else if(ratings[i] < ratings[i-1] && ratings[i] > ratings[i+1]){
                    continue;
                }
                else if(ratings[i] >= ratings[i-1] && ratings[i] > ratings[i+1]){
                    down_first = i;
                }
                else if(ratings[i] == ratings[i-1] && ratings[i] <= ratings[i+1]){
                    candies[i] = 1;
                }
            }
        }
        int sum = 0;
        for(int i = 0 ; i < length ; i ++){
            sum += candies[i];
        }
        return sum;
    }
};


//attempt1 : On On


class Solution {
public:
    int candy(vector<int>& ratings) {
        int length = ratings.size();
        int down_first = 0;
        int up_candy;
        int sum = 0;
        if(length == 1){return 1;}
        for(int i = 0 ; i < length ; i++){
            if(i == 0){
                if(ratings[i] <= ratings[i+1]){
                    sum += 1;
                    down_first = -1;
                    up_candy = 1;
                }
                else{
                    down_first = i;
                    up_candy = 0;
                }
            }
            else if(i == length-1){
                if(ratings[i] < ratings[i-1]){
                    int down_candy = 1;
                    sum += down_candy;
                    for(int j = i - 1 ; j > down_first ; j--){
                        down_candy = down_candy + 1;
                        sum += down_candy;
                    }
                    down_candy += 1;
                    if(down_first != 0 && ratings[down_first] > ratings[down_first-1])
                        down_candy = max(down_candy, up_candy + 1);
                    sum += down_candy;
                }
                else if(ratings[i] > ratings[i-1]){
                    up_candy = up_candy + 1;
                    sum += up_candy;
                }
                else{
                    sum += 1;
                }
            }
            else{
                if(ratings[i] < ratings[i-1] && ratings[i] <= ratings[i+1]){
                    int down_candy = 1;
                    sum += down_candy;
                    for(int j = i - 1 ; j > down_first ; j--){
                        down_candy = down_candy + 1;
                        sum += down_candy;
                    }
                    down_candy += 1;
                    if(down_first != 0 && ratings[down_first] > ratings[down_first-1])
                        down_candy = max(down_candy, up_candy + 1);
                    sum += down_candy;
                    up_candy = 1;
                }
                else if(ratings[i] > ratings[i-1] && ratings[i] <= ratings[i+1]){
                    up_candy = up_candy + 1;
                    sum += up_candy;
                }
                else if(ratings[i] < ratings[i-1] && ratings[i] > ratings[i+1]){
                    continue;
                }
                else if(ratings[i] >= ratings[i-1] && ratings[i] > ratings[i+1]){
                    down_first = i;
                    if(ratings[i] == ratings[i-1]) up_candy = 0;
                }
                else if(ratings[i] == ratings[i-1] && ratings[i] <= ratings[i+1]){
                    up_candy = 1;
                    sum += up_candy;
                }
            }
        }
        return sum;
    }
};


//attempt2: On O1