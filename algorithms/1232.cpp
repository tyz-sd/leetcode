#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double k;
        int length = coordinates.size();
        bool flg = 0;
        if(length <= 2)return 1;
        else{
            if(coordinates[0][0] == coordinates[1][0]){
                flg = 1;
            }
            else{
                k = ((double)coordinates[1][1] - (double)coordinates[0][1])/((double)coordinates[1][0] - (double)coordinates[0][0]);
            }
            if(flg){
                for(int i = 2 ; i < coordinates.size() ; i++){
                    if((double)coordinates[i][0] != (double)coordinates[0][0]) return false;
                }
                return true;
            }
            else{
                for(int i = 2 ; i < coordinates.size() ; i++){
                    if((double)coordinates[i][0] == (double)coordinates[0][0]) return false;
                    else{
                        if(k != ((double)coordinates[i][1] - (double)coordinates[0][1])/((double)coordinates[i][0] - (double)coordinates[0][0]))
                            return false;
                    }
                }
                return true;
            }
        }
        return true;
    }
};