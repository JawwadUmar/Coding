#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
bool simpleCheck(vector<vector<int>>& grid){
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

long long findSumTotalSum(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    long long totalSum = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            totalSum+= grid[i][j];
        }
    }

    return totalSum;
}

bool checkRowAsc(vector<vector<int>>& grid, long long totalSum){
        int n = grid.size();
        int m = grid[0].size();
        long long x = 0;
        long long y = 0;
        set<long long> st;
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                st.insert(grid[i][j]);
                x+=grid[i][j];
                y = totalSum - x;

                if(j == m-1){
                    if(i == 0){
                        if(grid[0][0] == x-y || grid[0][m-1] == x-y){
                            return true;
                        }
                    }

                    else if(st.find(x-y) != st.end()){
                        return true;
                    }
                }
            }
        }

        return false;
}

bool checkRowDesc(vector<vector<int>>& grid, long long totalSum){
        int n = grid.size();
        int m = grid[0].size();
       long long x = 0;
       long long  y = 0;
        set<long long> st;

        for(int i =n-1; i>=0; i--){
            for(int j = 0; j<m; j++){
                st.insert(grid[i][j]);
                x+=grid[i][j];
                y = totalSum - x;

                if(j == m-1){
                    if(i == n-1){
                        if(grid[n-1][0] == x-y || grid[n-1][m-1] == x-y){
                            return true;
                        }
                    }
                    else if(st.find(x-y) != st.end()){
                        return true;
                    }
                }
            }
        }


        return false;
}

bool checkColAsc(vector<vector<int>>& grid, long long totalSum){
        int n = grid.size();
        int m = grid[0].size();
       long long x = 0;
       long long  y = 0;
        set<long long> st;

         for(int j = 0; j<m; j++){
            for(int i = 0; i<n; i++){
                st.insert(grid[i][j]);
                x+=grid[i][j];
                y = totalSum - x;

                if(i == n-1){
                    if(j == 0){
                        if(grid[0][0] == x-y || grid[n-1][0] == x-y){
                            return true;
                        }
                    }
                    else if(st.find(x-y) != st.end()){
                        return true;
                    }
                }
                
            }
        }

        return false;
}

bool checkColDesc(vector<vector<int>>& grid, long long totalSum){
        int n = grid.size();
        int m = grid[0].size();
       long long x = 0;
       long long  y = 0;
        set<long long> st;

         for(int j = m-1; j>=0; j--){
            for(int i = 0; i<n; i++){
                st.insert(grid[i][j]);
                x+=grid[i][j];
                y = totalSum - x;

                if(i == n-1){
                    if(j == m-1){
                        if(grid[0][m-1] == x-y || grid[n-1][m-1] == x-y){
                            cout<<"here"<<endl;
                            return true;
                        }
                    }

                    else if(j == 1 && n == 1){
                        if(grid[i][j] == x-y || grid[i][m-1] == x-y){
                            return true;
                        }
                    }
                    else if(st.find(x-y) != st.end()){
                        cout<<x<<" "<<y<<endl;
                        return true;
                    }
                }
                
            }
        }

        return false;
}


bool checkOneRow(vector<vector<int>>& grid, long long total){
    int n = grid.size();
    int m = grid[0].size();

    if(m == 3 && grid[0][0] == grid[0][m-1]){
        return true;
    }

    long long x = 0;
    long long y = 0;

    for(int j = 0; j<m; j++){
        x+= grid[0][j];
        y = total-x;

        if(grid[0][0] == x-y){
            return true;
        }
        
        else if(grid[0][j] == x-y){
            return true;
        }
    }

    x = 0;
    y = 0;

    for(int j = m-1; j>=0; j--){
        x+= grid[0][j];
        y = total-x;

        if(grid[0][m-1] == x-y){
            return true;
        }
        else if(grid[0][j] == x-y){
            return true;
        }
    }

    return false;
}

bool checkOneCol(vector<vector<int>>& grid, long long total){
    int n = grid.size();
    int m = grid[0].size();

    if(n == 3 && grid[0][0] == grid[n-1][0]){
        return true;
    }

    long long x = 0;
    long long y = 0;

    for(int i = 0; i<n; i++){
        x+= grid[i][0];
        y = total-x;

        if(grid[0][0] == x-y){
            return true;
        }

        else if(grid[i][0] == x-y){
            return true;
        }
    }

    x = 0;
    y = 0;

    for(int i = n-1; i>=0; i--){
        x+= grid[i][0];
        y = total-x;

        if(grid[n-1][0] == x-y){
            return true;
        }
         else if(grid[i][0] == x-y){
            return true;
        }
    }

    return false;
}


public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long totalSum = findSumTotalSum(grid);

        

        if(simpleCheck(grid)){
            cout<<"Simple Check"<<endl;
            return true;
        }

         if(n == 1 && checkOneRow(grid, totalSum)){
            
            return true;
        }

        else if(n==1) {
            cout<<"checkOneRow"<<endl;
            return false;
        }

        if(m==1 && checkOneCol(grid, totalSum)){
            cout<<"checkOneCol"<<endl;
            return true;
        }

        else if(m==1){
            return false;
        }

        if(checkRowAsc(grid, totalSum)){
            cout<<"checkRowAsc"<<endl;
            return true;
        }

        if(checkRowDesc(grid, totalSum)){
            cout<<"checkRowDesc"<<endl;
            return true;
        }

        if(checkColAsc(grid, totalSum)){
            cout<<"checkColAsc"<<endl;
            return true;
        }

        if(checkColDesc(grid, totalSum)){
            cout<<"checkColDesc"<<endl;
            return true;
        }

       

    
        return false;
         
    }
};