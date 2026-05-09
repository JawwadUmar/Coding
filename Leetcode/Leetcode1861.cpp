#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<char>> rotateClockWise(vector<vector<char>>& boxGrid){
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>> res(m, vector<char>(n));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                res[j][i] = boxGrid[i][j];
            }
        }

        for(int i =0; i<res.size(); i++){
            reverse(res[i].begin(), res[i].end());
        }

        return res;
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        boxGrid = rotateClockWise(boxGrid);
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        for(int j = 0; j<m; j++){
            int lastObs = n;
            for(int i = n-1; i>=0; i--){
                if(boxGrid[i][j] == '*'){
                    lastObs = i;
                }
                else if(boxGrid[i][j] == '#'){
                    boxGrid[i][j] = '.';
                    boxGrid[lastObs-1][j] = '#';
                    lastObs = lastObs-1;
                }
            }
        }
        return boxGrid;
    }
};