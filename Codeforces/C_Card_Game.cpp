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

//ctrl shift B for output
// https://codeforces.com/problemset/problem/1882/C

void solve(){

    int n;
    cin>>n;

    vector<int> a(n+1);

    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }

    vector<int> suff(n+2, 0);

    for(int i = n; i>=1; i--){
        suff[i] = suff[i+1] + max((long long)0, a[i]);
    }

    // for(int i = 1; i<=n; i++){
    //     cout<<suff[i]<<" ";
    // }

    // cout<<endl;

    int ans = 0;

    for(int i = 1; i<=n; i++){
        
        if(i%2 !=0){
            ans = max(ans, suff[i+1]+a[i]);
        }

        else{
            ans = max(ans, suff[i+1]);
        }
    }

    cout<<ans<<endl;

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