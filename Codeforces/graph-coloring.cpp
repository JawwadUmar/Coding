#include <bits/stdc++.h>
using namespace std;

bool isSafeToColor(int node, int color, vector<int> &vis, vector<int> adj[]){

    for(int adjacentNode: adj[node]){
        if(vis[adjacentNode] == color){
            return false;
        }
    }

    return true;
}

bool canBeColored(int n, int node, vector<int> adj[], vector<int>&vis, int m){
    if(node == n){
        return true;
    }

    for(int color = 1; color<=m; color++){
        if(isSafeToColor(node, color, vis, adj)){
            vis[node] = color;
            bool flag = canBeColored(n, node+1, adj, vis, m);
            if(flag == true){
                return true;
            }
            vis[node] = 0;
        }
    }

    return false;
    
}

bool canBeColored(int n, vector<int> adj[], int m){

    vector<int> vis(n,0);

    for(int node = 0; node<n; node++){
        if(!vis[node]){
            bool flag = canBeColored(n, node, adj, vis, m);
            if(flag == false){
                return false;
            }
        }
    }

    return true;
    
}


void solve(){

    int n;
    cin>>n;

    int numberofEdges;
    cin>>numberofEdges;

    vector<int> edges;
    vector<int> adj[n];

    for(int i = 0; i<numberofEdges; i++){
        int u;
        int v;
        cin>>u;
        cin>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int minNoOfColors = 1;

    while (true)
    {

        if(canBeColored(n, adj, minNoOfColors)){
            cout<<minNoOfColors<<endl;
            return;
        }

        minNoOfColors++;
    }

}

int main(){
    
    solve();

}