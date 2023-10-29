#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

int f(int idx, vector<int> &coins, int x, vector<vector<int>> &dp){
    int n = coins.size();

    if(idx == n){
        if(x == 0){
            return 0;
        }

        return INT_MAX;
    }

    if(x< 0){
        return INT_MAX;
    }
    
    if(dp[idx][x] != -1){
        return dp[idx][x];
    }

    int p1, p2;
    p1 = p2 = INT_MAX;

    p1 = 1 + f(idx, coins, x - coins[idx], dp);
    p2 = f(idx+1, coins, x, dp);

    return dp[idx][x] = min(p1, p2);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin>>n>>x;

    vector<int> coins(n);

    for(int i = 0; i<n; i++){
        cin>>coins[i];
    }

    vector<vector<int>> dp(n+1, vector<int> (x+1, -1));
    int ans = f(0, coins, x, dp);

    if(ans == INT_MAX){
        cout<< -1<<endl;;
    }

    else{
        cout<<ans<<endl;
    }



}