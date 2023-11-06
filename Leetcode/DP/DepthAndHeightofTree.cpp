#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void dfs(int node, int parent, vector<int> adj[], vector<int>& depth, vector<int>& height){

    for(auto it: adj[node]){
        if(it != parent){
            depth[it] = 1 + depth[node];
            dfs(it, node, adj, depth, height);
            height[node] = max(height[node], 1 + height[it]);
        }
    }
}

void solve(){
    int n;
    cin>>n;

    vector<int> adj[n+1];

    for(int i =0; i<n-1; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n+1); //depth and distance are the same thing in case of trees
    vector<int> height(n+1);

    dfs(1, 0, adj, depth, height);

    for(int i = 1; i<=n; i++){
        cout<<"Node "<<i<<" Depth "<<depth[i]<<endl;
    }

    cout<<endl;

    for(int i = 1; i<=n; i++){
        cout<<"Node "<<i<<" Height "<<height[i]<<endl;
    }
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}