#include <bits/stdc++.h>
using namespace std;

//3D DP

int f(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){

    int n = grid.size();
    int m= grid[0].size();

    if(j1<0 || j2<0 || j1>=m || j2>=m){
        return -1e8;
    }

    if(i == n-1){
        if(j1 == j2){
            return grid[i][j1];
        }

        return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] !=-1){
        return dp[i][j1][j2];
    }

    int del[] = {-1, 0, 1};

    int res = INT_MIN;

    for(int idx1 =0; idx1<3; idx1++){
        for(int idx2 = 0; idx2<3; idx2++){
            
            if(j1 == j2){
                res = max(res, grid[i][j1] +  f(i+1, j1+ del[idx1], j2 + del[idx2], grid, dp));
            }

            else{
                res = max(res, grid[i][j1] + grid[i][j2] + f(i+1, j1+ del[idx1], j2 + del[idx2], grid, dp));
            }
        }
    }

    return dp[i][j1][j2] = res;
}


int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
   
   int n = grid.size();
   int m = grid[0].size();


   vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (m, -1)));

   return f(0, 0, m-1, grid, dp);
}