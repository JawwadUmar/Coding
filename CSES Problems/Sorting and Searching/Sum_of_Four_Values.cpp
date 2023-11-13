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


void solve(){

    int n, target;
    cin>>n>>target;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    map<int, pair<int, int>> mp;

    for(int i = 0; i<n; i++){

        for(int j = i+1; j<n; j++){
            int sum = a[i] + a[j];

            int req = target - sum;

            if(mp.find(req) != mp.end()){
                int k = mp[req].first;
                int l = mp[req].second;

                cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<l+1<<endl;
                return;
            }
        }

        for(int j = 0; j<i; j++){
            mp[a[i] + a[j]] = make_pair(i, j);
        }
    }

    cout<<"IMPOSSIBLE"<<endl;
    
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