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

bool isSafe(int row, int col, vector<string> &board){
    int x = row;
    int y = col;

    while (y>=0)
    {
        if(board[x][y] == 'Q'){
            return false;
        }

        y--;
    }
    
    x = row;
    y = col;

    while (y>=0 && x>=0)
    {
        if(board[x][y] == 'Q'){
            return false;
        }

        y--;
        x--;
    }

    x = row;
    y = col;

    while (y>=0 && x<8)
    {
        if(board[x][y] == 'Q'){
            return false;
        }

        y--;
        x++;
    }

    return true;
}

void placeInColumns(int col, vector<string>& board, int &cnt){
    if(col == 8){
        cnt++;
        return;
    }

    for(int row = 0; row<8; row++){
        if(board[row][col] != '*' && isSafe(row, col, board)){
            board[row][col] ='Q';
            placeInColumns(col+1, board, cnt);
            board[row][col] = '.';
        }
    }
}

void solve(){
    vector<string> board(8);

    for(int i = 0; i<8; i++){
        string s;
        cin>>s;

        board[i] = s;
    }

    int cnt = 0;

    placeInColumns(0, board, cnt);

    cout<<cnt<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    t=1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}