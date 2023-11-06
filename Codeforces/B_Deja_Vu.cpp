#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

void solve(){

    int n,q;
    cin>>n>>q;

    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    vector<int> queries(q);

    set<int> vis;
    vector<int> temp;

    for(int i = 0; i<q; i++){
        cin>>queries[i];
        
        if(vis.find(queries[i]) == vis.end()){
            temp.push_back(queries[i]);
            vis.insert(queries[i]);
        }
    }


    for(auto it: temp){
    int x = (1<<it);
        for(int i = 0; i<n; i++){
        if(a[i] % x == 0){
            a[i] += x/2;
        }
    }
}

    for(auto it: a){
        cout<<it<<" ";
    }

    cout<<endl;


    
    
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