#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
int binaryExponentiation(int x, int p){\
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

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}


void solve(){
    int n;
    cin>>n;

    vector<int> a(n);

    vector<pair<int, int>> v;
    for(int i = 0; i<n; i++){
        cin>>a[i];

        v.push_back({a[i], i});
    }

    vector<int> b(n);

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int cnt = 1;

    for(int i = 0; i<v.size(); i++){
        int idx = v[i].second;

        b[idx] = cnt;
        cnt++;
    }

    for(auto it: b){
        cout<<it<<" ";
    }

    cout<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    // t=1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}