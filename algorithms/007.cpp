class Solution {
public:
    int reverse(int x) {
        int reverse[32];
        int length = 0;
        int reverse_x = 0;
        bool flag = x < 0 ? 1 : 0;
        if(x == 0x80000000) return 0;
        x = abs(x);
        while(x){
            reverse[length] = x % 10;
            x /= 10;
            length += 1;
        }
        for(int i = 0 ; i < length ; i ++){
            if(reverse_x >= (int)0x7fffffff / 10 + 1){return 0;}
            reverse_x *= 10;
            reverse_x += reverse[i];
            if(reverse_x < 0){
                return 0;
            }
        }
        return flag ? - reverse_x : reverse_x ;
    }
};

