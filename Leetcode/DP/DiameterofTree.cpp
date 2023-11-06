#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

//ALGORITHM:
//1. With any root find the node with maximum depth
//2. With that obtained node as root, find the maximum depth/distance because that obtained node will be one of the two ends of diameter.

void dfs(int node, int parent, vector<int> adj[], vector<int> &depth){

    for(auto it: adj[node]){
        if(it!= parent){
            depth[it] = 1 + depth[node];
            dfs(it, node, adj, depth);
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

    vector<int> depth(n+1);
    dfs(1, 0, adj, depth); //lets find depth with 1 as root

    int mx_depthNode = -1;
    int mx_depth = 0;

    for(int node = 1; node<=n; node++){
        if(depth[node] > mx_depth){
            mx_depth = depth[node];
            mx_depthNode = node;
        }

        depth[node] = 0; //for reusability
    }

    //with obtained node, find the depths
    dfs(mx_depthNode, 0, adj, depth);

    //maximum depth will be the diameter
    int diameter = 0;

    for(int i =1; i<=n; i++){
        diameter = max(diameter, depth[i]);
    }

    cout<<diameter<<endl;

}

signed main(){
    solve();
}