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

    vector<pair<int, int>> v;
    map<int, int> mp;

    for(int i = 0; i<n; i++){
        int d, s;
        cin>>d>>s;

        v.push_back({d, s});
        if(mp.find(d) == mp.end()){
            mp[d] = s;
        }

        else{
        mp[d] = min(mp[d], s);

        }
    }

    //each move s-1/2 aage
    int ans = INT_MAX;

    for(int i = 1; i<=200; i++){

        if(mp[i]){
            int s = mp[i];
            int aage = (s-1)/2;
            ans = min(ans, i+aage);
        }
    }

    cout<<ans<<endl;

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