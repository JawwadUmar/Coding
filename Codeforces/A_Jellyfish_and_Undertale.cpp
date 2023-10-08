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

    int mxTime, b, n;
    cin>>mxTime>>b>>n;

    vector<int> a(n);

    multiset<int> m;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        m.insert(a[i]);
    }

    int res = 0;

    while (!m.empty())
    {
        res+= b-1;

        b= 1;

        auto it = m.begin();
        m.erase(it);

        b+= *it;

        b = min(b, mxTime);
    }

    // cout<<b<<endl;
    cout<<res + b<<endl;

    
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