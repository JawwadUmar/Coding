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
    int k;
    cin>>k;

    int cnt = 0;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int x1 = (a[i]|a[j]);
            int x2 = (a[i]&a[j]);

            // cout<<x1<<" "<<x2<<endl;

            if(numberOfSetBits(x1) + numberOfSetBits(x2) >=k){
                // cout<<i<<" "<<j<<endl;
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;

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