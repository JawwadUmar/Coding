#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> prefCol(n, vector<long long> (m, 0));
        long long currSum = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0 && j ==0){
                    prefCol[i][j] = grid[i][j];
                    currSum+=grid[i][j];
                    continue;
                }

                prefCol[i][j] = currSum + grid[i][j];
                currSum+= grid[i][j];
            }
        }

        if(currSum%2 != 0){
            return false;
        }

        for(int i = 0; i<n; i++){
            if(prefCol[i][m-1]*2 == currSum){
                return true;
            }
        }

         vector<vector<long long>> prefRow(m, vector<long long> (n, 0));
         currSum = 0;

         for(int j = 0; j<m; j++){
            for(int i = 0; i<n; i++){

                if(i == 0 && j ==0){
                    prefRow[j][i] = grid[i][j];
                    currSum+=grid[i][j];
                    continue;
                }

                prefRow[j][i] = currSum + grid[i][j];
                currSum+= grid[i][j];
            }
        }

        for(int i = 0; i<m; i++){
            if(prefRow[i][n-1]*2 == currSum){
                return true;
            }
        }

        return false;
         
    }
};