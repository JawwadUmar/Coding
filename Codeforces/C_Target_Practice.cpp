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

void solve(){

    vector<vector<int>> mat (11, vector<int> (11, 1));

    for(int i = 2; i<=9; i++){
        for(int j = 2; j<=9; j++){
            mat[i][j] = 2;
        }
    }


    for(int i = 3; i<=8; i++){
        for(int j = 3; j<=8; j++){
            mat[i][j] = 3;
        }
    }

    for(int i = 4; i<=7; i++){
        for(int j = 4; j<=7; j++){
            mat[i][j] = 4;
        }
    }


    for(int i = 5; i<=6; i++){
        for(int j = 5; j<=6; j++){
            mat[i][j] = 5;
        }
    }

    // for(int i = 1; i<=10; i++){
    //     for(int j = 1; j<=10; j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    
    int ans = 0;

    string s="";
    
    for(int i = 1; i<=10; i++){
        string temp;
        cin>>temp;
        s+= temp;
    }

    

    for(int i = 0; i<s.size(); i++){
        if(s[i] == 'X'){
            int r = i/10 + 1;
            int c = i%10 + 1;

            // cout<<r<<" "<<c<<endl;

            ans+= mat[r][c];
        }
    }

    cout<<ans<<endl;

    
    
   
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