#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> rank;
    vector<int> parent;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);

        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void UnionByRank(int u, int v){
        int u_p_u = findUltimateParent(u);
        int u_p_v = findUltimateParent(v);

        if(rank[u_p_u] > rank[u_p_v]){
            parent[u_p_v] = u_p_u;
        }

        else if(rank[u_p_u] < rank[rank[u_p_v]]){
            parent[u_p_u] = u_p_v;
        }

        else{
            parent[u_p_u] = u_p_v;
            rank[u_p_u]++;
        }
    }
};

class Solution
{
	public:
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<vector<int>> edges;
        
        for(int i = 0; i<n; i++){
            for(auto it: adj[i]){
                int v = it[0];
                int w = it[1];

                edges.push_back({w, i, v});
            }
        }
        
        sort(edges.begin(), edges.end());
        DisjointSet ds(n);
        int sum = 0;
        
        for(auto it: edges){
            int w = it[0];
            int u = it[1];
            int v = it[2];
            
            if(ds.findUltimateParent(u) == ds.findUltimateParent(v)){
                continue;
            }

            else{
                ds.UnionByRank(u, v);
                sum+= w;
            }
        }

        return sum;
    }
};