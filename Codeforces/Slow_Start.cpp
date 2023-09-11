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

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}


void solve(){
    int x, h;
    cin>>x>>h;

    int temp = 5;
    int cnt = 0;

    while (temp--)
    {
        h -= x/2;
        cnt++;

        if(h <=0){
            cout<<cnt<<endl;
            return;
        }
    }

    if(h%x ==0){
        cout<<cnt + h/x<<endl;
    }

    else{
        cout<<cnt+ h/x + 1<<endl;
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