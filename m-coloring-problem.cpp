#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool isSafeColor(int node, int color, vector<int> &vis, vector<int> adj[]){
        for(int adjacentNode: adj[node]){
            if(vis[adjacentNode] == color){
                return false;
            }
        }

        return true;
    }

    bool graphColoring(int node, vector<int>&vis, vector<int>adj[], int m) {
        int n = vis.size();

        if(node == n){
            return true;
        }
        
        for(int color = 1; color<=m; color++){
            if(isSafeColor(node, color, vis, adj)){
                vis[node] = color;
                bool flag = graphColoring(node+1, vis, adj, m);
                if(flag == true){
                    return true;
                }
                vis[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(int n, vector<vector<int>> &edges, int m) {

        vector<int> adj[n];
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n);
        
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                bool flag = graphColoring(i, vis, adj, m);
                if(flag == false){
                    return false;
                }
            }
        }

        return true;

    }
};