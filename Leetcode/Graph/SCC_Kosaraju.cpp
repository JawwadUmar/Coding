#include <bits/stdc++.h>
using namespace std;

void DfsSort(int node, vector<int> adj[] ,vector<int> &vis, stack<int> &st){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            DfsSort(it, adj, vis, st);
        }
    }

    st.push(node);
}

void dfs(int node, vector<int> adjT[], vector<int> &vis, vector<int> &v){
    vis[node] = 1;
    v.push_back(node);

    for(auto it: adjT[node]){
        if(!vis[it]){
            dfs(it, adjT, vis, v);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];
    vector<int> adjT[n];

    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adjT[v].push_back(u);
    }

    stack<int> st;
    vector<int> vis(n, 0);

    for(int i = 0; i<n; i++){
        if(!vis[i]){
            DfsSort(i, adj, vis, st);
        }
    }

    for(int i = 0; i<n; i++){
        vis[i] = 0;
    }

    int cnt = 0;

    vector<vector<int>> res;

    while(!st.empty()){
        int node = st.top();
        st.pop();
        vector<int> v;
        if(!vis[node]){
            cnt++;
            dfs(node, adjT, vis, v);
        }

        sort(v.begin(), v.end());

        if(!v.empty()){
            res.push_back(v);
        }
    }

    

    return res;


}