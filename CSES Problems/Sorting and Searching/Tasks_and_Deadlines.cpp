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


void solve(){

    int n;
    cin>>n;

    vector<pair<int,int>> v;

    for(int i = 0; i<n; i++){
        int dur, dead;
        cin>>dur>>dead;

        v.push_back({dur, dead});
    }

    sort(v.begin(), v.end());

    int res = 0;
    int pref = 0;
    for(int i = 0; i<n; i++){

        pref+= v[i].first;
        res+= v[i].second - pref;
    }

    cout<<res<<endl;
    
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