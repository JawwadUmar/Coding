#include <bits/stdc++.h>
using namespace std;


//Implement this in go bitch
class Solution {
private:
    int createRhombus(int r, int c, int sideLength, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if((r+sideLength >= n) || (c + sideLength>=m) || ((r + 2*sideLength) >=n) || ((c - sideLength)<0)){
            
            return 0;
        }

        if(sideLength == 0){
            return grid[r][c];
        }

        int temp = 0;
        int res = 0;
        while (temp <sideLength)
        {
            res+= grid[r][c];
            r = r + 1;
            c = c + 1;
            temp = temp+1;
        }

        temp = 0;
        while (temp < sideLength)
        {
           res+= grid[r][c]; 
           r = r+1;
           c = c-1;
           temp = temp+1;
        }

        temp = 0;
        while (temp < sideLength)
        {
           res+= grid[r][c]; 
           r = r-1;
           c = c-1;
           temp = temp+1;
        }

        temp = 0;
        while (temp < sideLength)
        {
           res+= grid[r][c]; 
           r = r-1;
           c = c+1;
           temp = temp+1;
        }
        
        return res;
        
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int sideLenght = (min(m, n) - 1)/2;
        set<int, greater<int>> multst;

        while (sideLenght>=0)
        {
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    int x = createRhombus(i, j, sideLenght, grid);
                    if(x!= 0){
                        multst.insert(x);
                    }
                }
            }

            sideLenght--;
        }
        // cout<<createRhombus(0, 1, 1, grid)<<endl;;

        vector<int> res;
        for(int x: multst){
            res.push_back(x);
            if(res.size() == 3){
                break;
            }
        }

        return res;
        
    }
};