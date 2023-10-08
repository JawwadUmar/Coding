#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;


void solve(){
    int n;
    cin>>n;

    vector<int> a(n);

    vector<int> freq(n, 0);

    for(int i = 0; i<n; i++){

        cin>>a[i];

        if(a[i] < n){
            freq[a[i]]++;
        }
    }

    int mex = -1;

    for(int i = 0; i<n; i++){
        if(freq[i] ==0){
            mex = i;
            break;
        }
    }

    if(mex == -1){
        mex = n;
    }

    if(mex == 0){
        cout<<0<<endl;
        return;
    }

    vector<int> dp(mex+1, INT_MAX);
    dp[mex] = 0;

    for(int i = mex; i>=1; i--){
        for(int j = 0; j<i; j++){
            dp[j] = min(dp[j], (i*(freq[j]-1) + j) + dp[i]);
        }
    }

    cout<<dp[0]<<endl;
    
    
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