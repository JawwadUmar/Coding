// https://codeforces.com/contest/1792/problem/B

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

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


void solve(){

    int a1, a2, a3, a4;
    cin>>a1>>a2>>a3>>a4;

    if(a1 == 0){
        cout<<1<<endl;
        return;
    }

    cout<< a1 + min(a2, a3)*2 + min(a1+1, abs(a3-a2) + a4)<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}