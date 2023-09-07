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


void solve(){
    int a, b, c;
    cin>>a>>b>>c;

    if(a==b){
        cout<<0<<endl;
        return;
    }

    if(a>b){
        swap(a, b);
    }

    //b>a
    double total = a+b;
    double each = total/2;

    double diff = b - each;

    double ans =diff/c;

    ans = ceil(ans);

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