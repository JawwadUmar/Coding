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


static bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.first < p2.first){
        return true;
    }

    if(p1.first == p2.first){
        return p1.second > p2.second;
    }

    return false;
}

void solve(){

    int n;
    cin>>n;

    map<pair<int, int>, int> mp;

    vector<pair<int, int>> v;

    for(int i = 0; i<n; i++){
        int l, r;
        cin>>l>>r;

        v.push_back({l, r});
        mp[v[i]] = i;
    }

    sort(v.begin(), v.end(), cmp);
    ordered_multiset<int> os;

    vector<int> contains(n, 0);

    for(int i = n-1; i>=0; i--){
        int x = os.order_of_key(v[i].second);
        int idx = mp[v[i]];
        contains[idx] = x;

        os.insert(v[i].second);
    }

    for(auto it: contains){
        cout<<it<<endl;
    }
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