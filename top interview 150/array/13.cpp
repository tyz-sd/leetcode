class Solution {
public:
    int romanToInt(string s) {
        int map[255];
        map[(int)'I'] = 1;
        map[(int)'V'] = 5;
        map[(int)'X'] = 10;
        map[(int)'L'] = 50;
        map[(int)'C'] = 100;
        map[(int)'D'] = 500;
        map[(int)'M'] = 1000;
        int length = s.length();
        int sum = 0;
        for(int i = 0 ; i < length ; i++){
            if(i == length - 1){
                sum += map[(int)s[i]];
            }
            else{
                if(map[(int)s[i]] < map[(int)s[i+1]]){
                    sum += map[(int)s[i+1]] - map[(int)s[i]];
                    i++;
                }
                else{
                    sum += map[(int)s[i]];
                }
            }
        }
        return sum;
    }
};