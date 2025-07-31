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

int f(int idx, int m, vector<vector<int>> &v){
    int n = v.size();
    if(idx >= n){
        return 0;
    }

    int l = v[idx][0];
    int r = v[idx][1];
    int p = v[idx][2];
    int q = v[idx][3];

    int take, not_take;
    take = not_take = 0;

    if(r == m){
        take = p/q;
    }

    not_take = f(idx+1, m, v);

    auto it = upper_bound(v.begin(), v.end(), vector<int>{r, -1, -1, -1});
    if(it == v.end()){
        return 0;
    }

    vector<int> temp = *it;
    int p1, p2;
    p1 = p2 = 0;
    if(temp[0] == r+1){
        p1 = p/q * f(it - v.begin(), m, v);
    }

    temp = v[idx+1];


    
}


void solve(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> v;

    for(int i = 0; i<n; i++){
        int l, r, p, q;
        cin>>l>>r>>p>>q;
        v.push_back({l, r, p, q});
    }

    sort(v.begin(), v.end());


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