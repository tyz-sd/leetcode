class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        vector<int> cites(1001, 0);
        int max_cite = 0;
        int min_cite = 0;
        for(int i = 0  ; i < length ; i++){
            for(int j = max_cite + 1 ; j <= citations[i] ; j++){
                cites[j] += 1;
                if(cites[j] == j){
                    max_cite = j;
                }
            }
        }
        return max_cite;
    }
};

//n^2 too slow

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int length = citations.size();
        int i;
        for(i = 1 ; i <= length ; i++){
            if(citations[i-1] < i){return i-1;}
        }
        return i-1;
    }
};

//nlogn fast