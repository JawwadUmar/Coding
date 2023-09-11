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


bool subarrayXor(int target, vector<int> &pref){
    int n = pref.size();
    vector<int> mp(256, 0);

    int cnt = 0;

    for(int i = 0; i<n; i++){
        mp[pref[i]]++;

        int x = pref[i]^target;

        if(pref[i] == target){
            return true;
        }

        if(x<= 255 && mp[x]!= 0){
            return true;
        }
    }

    return false;
}

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    int mx = INT_MIN;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        mx = max(a[i], mx);
    }

    vector<int> pref(n);
    pref[0] = a[0];


    for(int i = 1; i<a.size(); i++){
        pref[i] = a[i]^pref[i-1];
    }

    int ans = mx;

    for(int i =255; i>=mx; i--){

        if(subarrayXor(i, pref)){
            ans = i;
            break;
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