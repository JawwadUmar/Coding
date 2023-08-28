#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long


int binaryExponentiation(int x, int p, int MOD){

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
    int a, b, c;
    cin>>a>>b>>c;
    int MOD = 1e9+7;
    
    //compute r = (b^c)%(MOD-1)

    int r = binaryExponentiation(b, c, MOD-1);

    //compute (a^r)%MOD
    int res = binaryExponentiation(a, r, MOD);

    cout<<res<<endl;
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