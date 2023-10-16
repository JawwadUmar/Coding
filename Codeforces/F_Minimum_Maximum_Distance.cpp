#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
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

    int n, k;
    cin>>n>>k;

    vector<int> marked(k);

    for(int i = 0; i<k; i++){
        cin>>marked[i];
    }

    vector<vector<int>> edges;

    for(int i = 0; i<n-1; i++){
        int u, v;
        cin>>u>>v;

        edges.push_back({u ,v});
    }

    vector<int> f(n+1, 0);

    
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