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

int f(int idx, string &s, vector<int> &pref, vector<int> &suff, int flag, vector<vector<int>> &dp){
    int n = s.size();

    if(idx >= n){
        return 0;
    }

    if(dp[idx][flag] != -1){
        return dp[idx][flag];
    }

    if(s[idx] == 'A'){
        return f(idx+1,s,pref, suff, flag, dp);
    }

    //if s[idx] == 'B
    int p1 = INT_MIN;
    int p2 = INT_MIN;

    if(flag == 0){
        p1 = pref[idx] + f(idx+1, s, pref, suff, 1, dp);
        p2 = suff[idx] + f(idx+suff[idx]+1, s, pref, suff, 2, dp);

    }
    
    if(flag ==1){
         p1 = pref[idx] + f(idx+1, s, pref, suff, 1, dp);
         p2 = suff[idx] + f(idx+suff[idx]+1, s, pref, suff, 2, dp);
    }

    else{

        p2 = suff[idx] + f(idx+suff[idx]+1, s, pref, suff, 2, dp);

    }

      return dp[idx][flag] = max(p1, p2);

 }


void solve(){
    string s;
    cin>>s;
    int n = s.size();

    queue<int> indexes;

    if(s.size() <2){
        cout<<0<<endl;
        return;
    }

    vector<vector<int>> dp(n, vector<int> (3, -1));

    for(int i = 0; i<n; i++){
        if(s[i] == 'B'){
            indexes.push(i);
        }
    }

    vector<int> pref(n, 0);

    pref[0] = 0;

    if(s[0] == 'A'){
        pref[1]+= 1;
    }

    for(int i = 2; i<n; i++){
        if(s[i-1] == 'A'){
            pref[i] = pref[i-1]+1;
        }
    }

    // for(int i = 0; i<n; i++){
    //     cout<<pref[i]<<" ";
    // }

    // cout<<endl;

    vector<int> suff(n, 0);

    if(s.back() == 'A'){
        suff[n-2] = 1;
    }

    for(int i = n-3; i>=0; i--){
        if(s[i+1] == 'A'){
            suff[i] = suff[i+1] + 1;
        }
    }

    // for(int i = 0; i<n; i++){
    //     cout<<suff[i]<<" ";
    // }

    // cout<<endl;

    int idx = indexes.front();
    indexes.pop();

    // cout<<idx<<endl;

    cout<<f(0, s, pref, suff, 0, dp)<<endl;
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