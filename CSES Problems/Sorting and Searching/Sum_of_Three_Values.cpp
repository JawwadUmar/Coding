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

    int n, target;
    cin>>n>>target;

    vector<int> a(n);
    vector<pair<int, int>> v;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        v.push_back({a[i], i});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i<n; i++){

        int j = i+1;
        int k = n-1;

        while (j<k)
        {
            int A = v[i].second;
            int B = v[j].second;
            int C = v[k].second;

            if(a[A] + a[B] + a[C] == target){
                cout<<A+1<<" "<<B+1<<" "<<C+1<<endl;
                return;
            }

            else if(a[A] + a[B] + a[C] > target){
                k--;
            }

            else{
                j++;
            }
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