
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
#define endl '\n'
 
static bool cmp (pair<int, int> p1, pair<int, int> p2){
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
 
    map<pair<int, int> , int> mp;
    vector<pair<int, int>> v;
 
    for(int i = 0; i<n; i++){
        int a, b;
        cin>>a>>b;
 
        mp[make_pair(a, b)] = i;
        v.push_back({a, b});
    }
 
    sort(v.begin(), v.end(), cmp);
 
    ordered_multiset<int> os;
 
 
    vector<int> contained(n, 0);
 
    os.insert(v[0].second);
 
    for(int i = 1; i<n; i++){
 
        int x = os.size() - os.order_of_key(v[i].second); //x right elements are larger or equal
        int idx = mp[v[i]];
        contained[idx] = x;
        os.insert(v[i].second);
    }
 
    vector<int> contains(n, 0);
    os.clear();
 
    for(int i = n-1; i>=0; i--){
 
        int x = os.order_of_key(v[i].second);
        int cnt = os.order_of_key(v[i].second+1) - os.order_of_key(v[i].second);
        int idx = mp[v[i]];
 
        contains[idx] = x + cnt >=0 ? x + cnt : 0;
        os.insert(v[i].second);
    }
 
    for(auto it: contains){
        cout<<it<<" ";
    }
 
    cout<<endl;
 
    for(auto it: contained){
        cout<<it<<" ";
    }
}
 
signed main(){
    solve();
}