#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
int binaryExponentiation(int x, int p){
    int res = 1;
    while(p){
        if(p%2){
            res = (res * x)%MOD;
        }

        x = (x*x)%MOD;
        p = p/2;
    }
    
    return res;
}

int rowCount(int r, vector<vector<char>> &grid, char ch){
    int cnt = 0;

    int m = grid[r].size();

    for(int i=0; i<m; i++){
        if(grid[r][i] == ch){
            cnt++;
        }
    }

    return cnt;
    
}

int colCount(int c, vector<vector<char>> &grid, char ch){
    int cnt = 0;

    int m = grid.size();

    for(int i=0; i<m; i++){
        if(grid[i][c] == ch){
            cnt++;
        }
    }

    return cnt;

}

void LR(vector<vector<char>> &grid, bool &flag){
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){

            if(grid[i][j] == 'L'){
                if(flag){
                    grid[i][j] = 'W';
                    grid[i][j+1] = 'B';
                    flag = 1 - flag;
                }

                else{
                    grid[i][j] = 'B';
                    grid[i][j+1] = 'W';
                    flag = 1 - flag;
                }
            }
        }
    }
}


void UD(vector<vector<char>> &grid, bool &flag){
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){

            if(grid[i][j] == 'U'){
                if(flag){
                    grid[i][j] = 'W';
                    grid[i+1][j] = 'B';
                    flag = 1 - flag;
                }

                else{
                    grid[i][j] = 'B';
                    grid[i+1][j] = 'W';

                    flag = 1 - flag;
                }
            }
        }
    }
}

bool check(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();


    for(int i = 0; i<n; i++){
        int white_in_row = rowCount(i, grid, 'W');
        int black_in_row = rowCount(i, grid, 'B');

        if(white_in_row != black_in_row){
            return false;
        }
    }

    for(int j = 0; j<m; j++){
        int white_in_col = colCount(j, grid, 'W');
        int black_in_col = colCount(j, grid, 'B');

        if(white_in_col != black_in_col){
            return false;
        }
    }

    return true;
}

void print(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}




void solve(){
    int n, m;
    cin>>n>>m;

    vector<vector<char>> board (n, vector<char> (m, '.'));
    

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            char ch;
            cin>>ch;

            board[i][j] = ch;

        }
    }

    vector<vector<char>> grid = board;

    for(int i = 0; i<n; i++){
        int cnt = 0;
    for(int j = 0; j<m; j++){
        if(grid[i][j] == 'U'){
            if(cnt%2 == 0){
            grid[i][j] = 'B';
            grid[i+1][j] = 'W';

            }

            else{
            grid[i][j] = 'W';
            grid[i+1][j] = 'B';
            }
            cnt++;
         }
    }

    if(cnt%2){
        cout<<-1<<endl;
        return;
    }


    }

    for(int j = 0; j<m; j++){
        int cnt = 0;

        for(int i = 0; i<n; i++){
            if(grid[i][j] == 'L'){
                if(cnt%2 == 0){
                    grid[i][j] = 'B';
                    grid[i][j+1] = 'W';
                }

                else{
                    grid[i][j] = 'W';
                    grid[i][j+1] = 'B';
                }
                cnt++;
            }
        }

        if(cnt%2){
            cout<<-1<<endl;
            return;
        }
    }

    print(grid);
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    // t=1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}