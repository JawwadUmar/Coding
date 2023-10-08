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

    for(int i =0; i<n; i++){
        cin>>a[i];
    }

    vector<int> pref(n);
    vector<int> suff(n);

    pref[0] = a[0];

    for(int i = 1; i<n; i++){
        pref[i] = pref[i-1] + a[i];
    }

    suff[n-1] = a[n-1];

    for(int i = n-2; i>=0; i--){
        suff[i] = suff[i+1] + a[i];
    }

    int ans = 1;

    for(int i = 0; i<n-1; i++){

        ans = max(ans, __gcd(pref[i], suff[i+1]));
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