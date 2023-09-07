#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int n, int edges, int source) {

    vector<pair<int, int>> adj[n];

    for(auto it: vec){
        int u = it[0];
        int v = it[1];
        int w = it[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue< pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;

    pq.push({0, source});
    vector<int> ans(n, INT_MAX);
    ans[source] = 0;

    while(!pq.empty()){

        int node = pq.top().second;
        int d = pq.top().first;

        pq.pop();

        for(auto it: adj[node]){
            int adjacentNode = it.first;
            int w = it.second;

            if(d+ w < ans[adjacentNode]){
                pq.push({d+w, adjacentNode});
                ans[adjacentNode] = d+w;
            }
        }
    }

    return ans;
}
