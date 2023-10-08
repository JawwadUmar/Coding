#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
int binaryExponentiation(int x, int p){\
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

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}


bool check(int row, int col, vector<string> &v){

    int r = row;
    int c = col;

    while (r>=1 && c>=1)
    {
        if(v[r][c] != '#'){
            return false;
        }

        r--;
        c--;
    }

    r = row;
    c = col;

    while (r>=1 && c<=8)
    {
        if(v[r][c] != '#'){
            return false;
        }

        r--;
        c++;
    
    }

    r = row;
    c = col;

    while (r<=8 && c>=1)
    {
        if(v[r][c] != '#'){
            return false;
        }

        r++;
        c--;
    
    }

     r = row;
    c = col;

    while (r<=8 && c<=8)
    {
        if(v[r][c] != '#'){
            return false;
        }

        r++;
        c++;
    
    }

    return true;
}


void solve(){
    
    vector<string> v(9);

    for(int i = 1; i<=8; i++){
        string s;
        cin>>s;

        s = "?" + s;
        v[i] = s;
    }

    for(int i = 1; i<=8; i++){
        for(int j = 1; j<=8; j++){

            if(i == 1 && j == 1 || i == 8 && j == 1 || i == 1 && j == 8 || i == 8 && j ==8){
                continue;
            }

            if(v[i][j] != '#'){
                continue;
            }

            // cout<<i<<" "<<j<<endl;

            if(check(i, j, v)){
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }

    cout<<"Jae"<<endl;


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