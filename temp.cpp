#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
#define endl '\n'
#define int long long


void solve(){

    int n;
    cin>>n;

    vector<int> a(n);

    vector<int> dp(n+2, 0);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    for(int i = n-1; i>=0; i--){
        int take = a[i] + dp[i+2];
        int not_take = dp[i+1];

        dp[i] = max(take, not_take);
    }
    
    cout<<dp[0]<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}