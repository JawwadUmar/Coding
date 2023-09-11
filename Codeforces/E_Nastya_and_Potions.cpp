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

int f(int node, vector<vector<int>> &adj, vector<int> &cost){
    int res = 0;

    if(adj[node].empty()){
        return cost[node];
    }

    for(auto it: adj[node]){
        res+= cost[it];
    }

return res;
    
}

int dfs(int node, vector<vector<int>> &adj, vector<int> &cost, vector<int> &dp){

    if(dp[node] != -1){
        return dp[node];
    }

    dp[node] = cost[node];
    int aux = 0;

    for(auto it: adj[node]){
        aux+= dfs(it, adj, cost, dp);
    }

    return dp[node] = min(dp[node], aux);
}

void solve(){
    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<int> cost(n+1);

    for(int i=1; i<=n; i++){
        cin>>cost[i];
    }

    vector<int> indexes(k+1);

    vector<vector<int>> adj(n+1);
    vector<int> dp(n+1, -1);


    for(int i = 1; i<=k; i++){
        cin>>indexes[i];
        dp[indexes[i]] =0;
    }


   

    for(int i = 1; i<=n; i++){
        int m;
        cin>>m;

        if(m==0){
            if(dp[i] != 0){
                dp[i] = cost[i];
            }
        }

        while (m--)
        {
            int x;
            cin>>x;
            adj[i].push_back(x);

        }
    }

    for(int i =1; i<=n; i++){
        if(dp[i] ==-1){
            dfs(i, adj, cost, dp);
        }
    }
    
    for(int i =1; i<=n; i++){
        cout<<dp[i]<<" ";
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