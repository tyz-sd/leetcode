class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos = s.length() - 1;
        int len = 0;
        while(-1 != pos && s[pos] == ' '){pos--; }
        while(-1 != pos && s[pos] != ' ') {pos--; len++;}
        return len;
    }
};