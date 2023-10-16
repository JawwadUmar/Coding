#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<string> f(int n){

    if(n==0){
        return {"0"};
    }

    if(n==1){
        return {"0", "1"};
    }

    vector<string> l = f(n-1);
    vector<string> r = l;
    reverse(r.begin(), r.end());

    for(auto &it: l){
        it = "0" + it;
    }

    for(auto &it: r){
        it = "1"+ it;
    }

    vector<string> res;

    for(auto it: l){
        res.push_back(it);
    }

    for(auto it: r){
        res.push_back(it);
    }

    return res;
}

void solve(){
    int n;
    cin>>n;

    vector<string> s = f(n);

    for(auto it: s){
        cout<<it<<endl;
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