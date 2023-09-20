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
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());

    vector<int> res(n, 0);
    int idx = 0;

    for(int i = 0; i<n; i+=2){
        res[i] = a[idx];
        idx++;
    }

    for(int i = 1; i<n; i+=2){
        res[i] = a[idx];
        idx++;
    }

    for(int i = 1; i<n; i++){
        if(res[i] == res[i-1]){
            cout<<"-1"<<endl;
            return;
        }
    }

    for(int i = 0; i<n; i++){
        cout<<res[i]<<" ";
    }

    cout<<endl;
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