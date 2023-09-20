#include <bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int M, vector<pair<pair<int, int>, int>> &g){
    
   vector<vector<int>> adj[n+1];
   for(auto it: g){
       int u = it.first.first;
       int v = it.first.second;
       int w = it.second;

       adj[u].push_back({v, w});
       adj[v].push_back({u, w});
   }
   vector<int> vis(n+1, 0);
   vector<int> key(n+1, 0);
   vector<int> pt(n+1, 0);
        
        multiset< vector<int> > m;
        vector<pair<pair<int, int>, int>> res;
        
        m.insert({0, 1, 0});
        int sum = 0;
        
        while(!m.empty()){
            auto pit = *(m.begin());
            int node = pit[1];
            int wt = pit[0];
            int parent = pit[2];
            
            m.erase(m.begin());
            
            if(vis[node]){
                continue;
            }
            
            vis[node] = 1;
            key[node] = wt;
            pt[node] = parent;

           
            
            for(auto it: adj[node]){
                int child = it[0];
                int w = it[1];
                
                if(!vis[child]){
                    m.insert({w, child, node});
                }
                
            }
        }

        for(int i = 2; i<=n; i++){
            res.push_back({{pt[i], i}, key[i]});
        }


        return res;
        
}
