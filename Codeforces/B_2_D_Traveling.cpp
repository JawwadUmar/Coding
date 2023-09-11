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
    int n, k, a, b;
    cin>>n>>k>>a>>b;

    vector<pair<int, int>> v;
    map< pair<int, int>, int> mp;

    for(int i = 0; i<n; i++){
        int x, y;
        cin>>x>>y;

        v.push_back({x, y});
        mp[{x, y}] = i+1;
    }

    //v[a-1] to v[b-1]

    if(mp[v[a-1]] <=k && mp[v[b-1]]<=k){
        cout<<0<<endl;
        return;
    }


    int res1 = abs(v[a-1].first - v[b-1].first) + abs(v[a-1].second - v[b-1].second);

    //closest to v[a-1]
    //closest to v[b-1]

    int cnt1 = 1e18;
    int cnt2 = 1e18;


    for(int i = 0; i<k; i++){
        if(abs(v[a-1].first - v[i].first) + abs(v[a-1].second - v[i].second) < cnt1){
            cnt1 = abs(v[a-1].first - v[i].first) + abs(v[a-1].second - v[i].second);
        }

        if(abs(v[b-1].first - v[i].first) + abs(v[b-1].second - v[i].second) < cnt2){
            cnt2 = abs(v[b-1].first - v[i].first) + abs(v[b-1].second - v[i].second);
        }
    }

    int res2 = cnt1+ cnt2;

    cout<<min(res1, res2)<<endl;
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