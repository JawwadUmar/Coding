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


int n;
vector<double> c, p;
vector<double> dp;

double f(int i){
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];

    double skip = f(i+1);
    double take = c[i] + (1.0 - p[i]/100.0) * f(i+1);

    return dp[i] = max(skip, take);
}

void solve(){
    int n;
    cin>>n;

    vector<int> c(n);
    vector<int> p(n);

    vector<int> mxc(n);
    
    for(int i = 0; i<n; i++){
        int ci, pi;
        cin>>ci>>pi;

        c[i] = ci;
        p[i] = pi;
    }

    set<int> indexes;
    indexes.insert(n-1);
    double curr = c[n-1]*1.0;

    for(int i = n-2; i>=0; i--){
        double take = c[i]*1.0 + (1.0-((p[i]*1.0)/100.0))*curr;
        if(take > curr){
            curr = take;
            indexes.insert(i);
        }
    }

    double res = 0;
    double s =1.0;

    for(int idx: indexes){
        double ci = c[idx]*1.0;
        double pi = p[idx]*1.0;

        res+= s*ci;
        s = s* (1.0-((pi*1.0)/100.0));
    }

    cout<<res<<endl;
}

// void solve(){
//     int n;
//     cin >> n;

//     vector<double> c(n), p(n);

//     for(int i=0;i<n;i++){
//         cin >> c[i] >> p[i];
//         p[i] = 1.0 - p[i]/100.0;
//     }

//     double dp = 0;

//     for(int i=n-1;i>=0;i--){
//         dp = max(dp, c[i] + p[i]*dp);
//     }

//     cout << fixed << setprecision(10) << dp << endl;
// }

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