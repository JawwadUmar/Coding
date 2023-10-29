#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'


int f(int idx, int flag, vector<int> &a, vector<vector<int>> &mp, vector<vector<int>> &dp){

    int n = a.size();
    if(idx == n){
        return 0;
    }

    if(dp[idx][flag] != -1){
        return dp[idx][flag];
    }

    int p1, p2, p3, p4;
    p1 = p2 = p3 = p4 = INT_MAX;

    int res = 0;

    int curr_num = a[idx];
    auto ind= upper_bound(mp[curr_num].begin(), mp[curr_num].end(), idx);

    if(ind != mp[curr_num].end()){
        p1 = f(*ind, 1, a, mp, dp);
    }

    if(flag == 0){
        p2 = 1 + f(idx+1, 0, a, mp, dp);
    }

    else if(flag == 1){
        p3 = f(idx+1, 0, a, mp, dp);
    }

    

    res = min({p1, p2, p3});

    return dp[idx][flag] = res;
}


void solve(){

    int n;
    cin>>n;

    vector<int> a(n);
    vector<vector<int>> mp (n+1);

    for(int i = 0; i<n; i++){
        cin>>a[i];
        mp[a[i]].push_back(i);
    }

    // vector<int> dp(n+1, -1);
    vector<vector<int>> dp(n+1, vector<int> (3, -1));
    cout<<n - f(0, 0, a, mp, dp)<<endl;


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