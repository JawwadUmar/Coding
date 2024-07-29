#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long




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

int f(int x, vector<int> &a, vector<int> &dp){
    if(x == 0){
        return 0;
    }

    if(dp[x] != 1e18){
        return dp[x];
    }

    int ans = 1e18;

    for(int i = 0; i<a.size(); i++){
        if(a[i] <= x){
            ans = min(ans, 1+f(x-a[i], a, dp));
        }
    }

    return ans;
}


void solve(){

    int n, x;
    cin>>n>>x;

    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    vector<int> dp(x+1, 1e18);
    dp[0] = 0;

    for(int i = 1; i<=x; i++){
        for(int j = 0; j<n; j++){
            if(i>=a[j]){
                dp[i] = min(dp[i], 1 + dp[i - a[j]]);
            }
        }
    }

    int ans = dp[x] == 1e18 ? -1 : dp[x];
    cout<< ans <<endl;


}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}