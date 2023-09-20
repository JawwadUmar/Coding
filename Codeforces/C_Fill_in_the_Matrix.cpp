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
    int n, m;
    cin>>n>>m;

    if(m==1){
        cout<<0<<endl;

        for(int i = 0; i<n; i++){
            cout<<0<<endl;
        }

        return;
    }

    int res = min(n+1, m);

    vector<vector<int>> mat(n, vector<int>(m, 0));

    cout<<res<<endl;

    if(n+1>=m){

        // cout<<"here"<<endl;

        for(int i = 0; i<m-1; i++){
            for(int j = 0; j<m; j++){
                // cout<<"1"<<endl;
                mat[i][j] = (i+j+1)%m;
            }
        }

        for(int i=m-1; i<n; i++){
            for(int j = 0; j<m; j++){
                // cout<<"2"<<endl;
                mat[i][j] = mat[i-1][j];
            }
        }

    }

    else{
        
        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                mat[i][j] = (i+j)%m;
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j =0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    } 
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