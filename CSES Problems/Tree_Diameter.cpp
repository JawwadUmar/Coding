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

int res = 0;

int f(int node, int parent, vector<int> adj[]){

    int largest, secondLargest;
    largest = secondLargest = 0;

    for(auto it: adj[node]){
        if(it != parent){
            int childLen = f(it, node, adj);

            if(childLen> secondLargest){
                secondLargest = childLen;

                if(secondLargest > largest){
                    swap(secondLargest, largest);
                }
            }
        }
    }

    res = max({res, 1+largest+secondLargest});
    return max(1+largest, 1+secondLargest);
}


void solve(){

    int n;
    cin>>n;

    vector<int> adj[n+1];

    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    f(1, 0, adj);

    cout<<res-1<<endl;
    
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