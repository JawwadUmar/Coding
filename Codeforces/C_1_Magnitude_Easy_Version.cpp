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


// int f(int idx, vector<int> &a, vector<int> &dp){
//     int n = a.size();

//     if(idx == n){
//         return 0;
//     }

//     if(dp[idx] != -1e18){
//         return dp[idx];
//     }

//     int c = 0;
    
//     int p1 = c+a[idx] + f(idx+1, a, dp);
//     int p2 = abs(c+a[idx]) + f(idx+1, a, dp);

//     return dp[idx] = max(p1, p2);
// }

void solve(){

    int n;
    cin>>n;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }


    // vector<int> dp(n+1, -1e18);
    // cout<<f(0, a, dp)<<endl;

    vector<int> prefSum(n, 0);

    prefSum[0] = a[0];

    for(int i = 1; i<n; i++){

        if(prefSum[i-1] < 0 && a[i] + prefSum[i-1] >=0){
            prefSum[i] = a[i] + abs(prefSum[i-1]);
        }

        else if(prefSum[i-1] > 0 && a[i] + prefSum[i-1] <=0){
            prefSum[i] = abs(a[i] + prefSum[i-1]);
        }

        else{
            prefSum[i] = a[i] + prefSum[i-1];
        }
    }

    int ans1  =abs(prefSum.back());

    for(auto &it: prefSum){
        it = 0;
    }


    prefSum[0] = abs(a[0]);
    for(int i = 1; i<n; i++){

        if(prefSum[i-1] < 0 && a[i] + prefSum[i-1] >=0){
            prefSum[i] = a[i] + abs(prefSum[i-1]);
        }

        else if(prefSum[i-1] > 0 && a[i] + prefSum[i-1] <=0){
            prefSum[i] = abs(a[i] + prefSum[i-1]);
        }

        else{
            prefSum[i] = a[i] + prefSum[i-1];
        }
    }

    int ans2 = abs(prefSum.back());

    int ans3  =0;

    for(auto it: a){
        ans3+= it;
    }

    ans3 = abs(ans3);

    cout<<max({ans1, ans2, ans3})<<endl;

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