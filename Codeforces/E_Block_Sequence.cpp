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

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}


int f(int idx, vector<int>&a, vector<int> &dp){

    int n = a.size();

    if(idx > n){
        return 1e8;
    }

    if(idx == n){
        return 0;
    }

    if(dp[idx] != -1){
        return dp[idx];
    }

    int not_remove = f(idx+ a[idx]+1, a, dp);
    int remove = 1 + f(idx+1, a, dp);

    return dp[idx] = min(not_remove, remove);
}


void solve(){

    int n;
    cin>>n;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    vector<int> dp(n+1, -1);
    cout<<f(0, a, dp)<<endl;
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