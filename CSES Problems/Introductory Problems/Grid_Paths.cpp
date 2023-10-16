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

//ctrl shift B for output

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}


int f(int r, int c, int idx, string &s, vector<vector<int>> &vis){

    int n = s.size();

    if(idx == n){

        if(r == 6 && c == 0){
            return 1;
        }

        return 0;
    }

    if(r == 6 && c==0){
        return 0;
    }

    if(r<0 || r>6 || c<0 || c>6){
        return 0;
    }

    if(vis[r][c]){
        return 0;
    }

    bool hitwall = false;

    if(r == 0 && c-1>=0 && c+1<=6 && vis[r][c-1] ==0 && vis[r][c+1] ==0){
        hitwall = true;
        return 0;
    }

    if(r==6 && c-1>=0 && c+1<=6 && vis[r][c-1] == 0 && vis[r][c+1] ==0){
        hitwall = true;
        return 0;
    }

    if(c==6 && r-1>=0 && r+1<=6 && vis[r-1][c] == 0 && vis[r+1][c] ==0){
        hitwall = true;
        return 0;
    }

    if(c==0 && r-1>=0 && r+1<=6 && vis[r-1][c] == 0 && vis[r+1][c] ==0){
        hitwall = true;
        return 0;
    }

    if(hitwall){
        return 0;
    }

    bool cannot = false;

    if(r-1>=0 && r+1 <=6 && c-1>=0 && c+1<=6){

    if(vis[r][c-1] && vis[r][c+1] && vis[r-1][c] ==0 && vis[r+1][c] ==0){
        cannot = true;
        return 0;
    }

    if(vis[r-1][c] && vis[r+1][c] && vis[r][c-1] ==0 && vis[r][c+1] == 0){
        cannot = true;
        return 0;
    }

    }
   
    if(cannot){
        return 0;
    }

    bool cornerCase = false;

    if(c-1 >= 0 && r-1>=0 && vis[r][c-1] ==0 && vis[r-1][c] == 0 && vis[r-1][c-1] ==1){
        cornerCase = true;
    }

    if(c+1<=6 && r+1<=6 && vis[r][c+1] ==0 && vis[r+1][c] == 0 && vis[r+1][c+1] ==1){
        cornerCase = true;
    }

    if(c-1>=0 && r+1<=6 && vis[r][c-1] ==0 && vis[r+1][c] ==0 && vis[r+1][c-1] ==1){
        cornerCase = true;
    }

    if(r-1 >=0 && c+1 <=6 && vis[r-1][c] ==0 && vis[r][c+1] ==0 && vis[r-1][c+1] ==1){
        cornerCase = true;
    }

    if(cornerCase){
        return 0;
    }

    vis[r][c] = 1;

    int left = 0;
    int right = 0;
    int up = 0;
    int down = 0;

    if(s[idx] == 'R' || s[idx] == '?'){ 
        right+= f(r, c+1, idx+1, s, vis);
    }

    if(s[idx] == 'L' || s[idx] == '?'){
        left+= f(r, c-1, idx+1,s, vis);
    }

    if(s[idx] == 'U' || s[idx] == '?'){
        up+= f(r-1, c, idx+1, s, vis);
    }

    if(s[idx] == 'D' || s[idx] == '?'){
        down+= f(r+1, c, idx+1, s, vis);
    }

    vis[r][c] = 0;

    return left+right+down+up;
}

void solve(){
    string s;
    cin>>s;

    vector<vector<int>> vis (7, vector<int> (7, 0));

    cout<<f(0, 0, 0, s, vis)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}