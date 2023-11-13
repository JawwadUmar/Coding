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

    vector<pair<pair<int, int>, int>> v;

    for(int i = 0; i<n; i++){
        int x, y;
        cin>>x>>y;

        v.push_back({{x, y}, i});
    }

    sort(v.begin(), v.end());
    multiset<pair<int,int>> m;
    m.insert({v[0].first.second, 1});
    vector<int> res(n);
    res[v[0].second] = 1;
    int k = 1;

    for(int i = 1; i<n; i++){

        auto it = m.begin();
        int idx = v[i].second;

        if(v[i].first.first > it->first){

            int temp = it->second;
            m.erase(it);
            m.insert({v[i].first.second, temp});
            res[idx] = temp;
        }

        else{
            k++;
            m.insert({v[i].first.second, k});
            res[idx] = k;
        }
    }

    cout<<k<<endl;

    for(auto it: res){
        cout<<it<<" ";
    }

    cout<<endl;


    
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