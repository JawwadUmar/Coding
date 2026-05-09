#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void rotateMat(int topRow, int topCol, int bottomRow, int bottomCol,  int n, int m, vector<vector<int>>& grid, int k){
        if(n<2 || m<2){
            return;
        }

        int totalElements = 2*(m+n) - 4;
        int totalRotationsReq = k%totalElements;

        while(totalRotationsReq){
            for(int j = topCol; j<=bottomCol-1; j++){
            swap(grid[topRow][j], grid[topRow][j+1]);
        }
        

        for(int i = topRow; i<=bottomRow-1; i++){
            swap(grid[i][bottomCol], grid[i+1][bottomCol]);
        }
        

        for(int j =bottomCol; j>=topCol+1; j--){
            swap(grid[bottomRow][j], grid[bottomRow][j-1]);
        }
        

        for(int i = bottomRow; i>=topRow+2; i--){
            swap(grid[i][topCol], grid[i-1][topCol]);
        }
        totalRotationsReq-=1;
        }
        
        rotateMat(topRow+1, topCol+1,bottomRow-1,bottomCol-1,n-2, m-2, grid, k);
    }

    void printGrid(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        rotateMat(0, 0, n-1, m-1, n, m, grid, k);
        return grid;

    }
};