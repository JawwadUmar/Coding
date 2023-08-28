#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

void TOH(int n, int a, int b, int c, vector<pair<int, int>> &res){
    if(n==1){
        res.push_back({a, c});
        return;
    }

    TOH(n-1, a, c, b, res);
    res.push_back({a, c});
    TOH(n-1, b, a, c, res);
}

void solve(){
    int n;
    cin>>n;

    vector<pair<int, int>> res;
    TOH(n, 1, 2, 3, res);

    cout<<res.size()<<endl;

    for(auto it: res){
        cout<<it.first<<" "<<it.second<<endl;
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    t=1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}