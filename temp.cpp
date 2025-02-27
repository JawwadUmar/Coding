
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool findBobsPath(int node, vector<int> &res, vector<int> &vis, vector<int> adj[]){
            if(node == 0){
                return true;
            }
    
            vis[node] = 1;
    
            for(auto it: adj[node]){
                if(!vis[it]){
                    res.push_back(it);
                    bool take = findBobsPath(it, res, vis, adj);
                    if(take){
                        return true;
                    }
    
                    res.pop_back();
                }
            }
    
            return false;
        }
    
        int mostProfitablePath(int Alice_node, int Bob_node_index, vector<int> &bobs_path, vector<int>& amount, vector<int> &vis, vector<int> adj[]){


            vis[Alice_node] = 1;
            int Bob_node = -1;
            if(Bob_node_index < bobs_path.size()){
                Bob_node = bobs_path[Bob_node_index];
            }

            int x = 0;
            int alice_pay = amount[Alice_node];
            int bob_pay;
    
            if(Alice_node == Bob_node){
                x+= amount[Alice_node]/2;
            }

            else{
                x+= amount[Alice_node];
            }

            amount[Alice_node] = 0;

            if(Bob_node != -1){
                bob_pay = amount[Bob_node];
                amount[Bob_node] = 0;
            }

            int res = -1e9;

            for(auto it:adj[Alice_node]){
                if(!vis[it]){
                    res = max(res, x + mostProfitablePath(it, Bob_node_index, bobs_path, amount, vis, adj));
                }
            }

            amount[Alice_node] = alice_pay;
            if(Bob_node != -1){
                amount[Bob_node] = bob_pay;
            }

            return 0;

        }
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = edges.size() + 1;
            vector<int> adj[n];
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
    
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            vector<int> bobs_path;
            vector<int> vis(n, 0);
            bobs_path.push_back(bob);
            findBobsPath(bob, bobs_path, vis, adj);
    
            fill(vis.begin(), vis.end(), 0);
    
            int res = mostProfitablePath(0, 0, bobs_path, amount, vis, adj);
    
            return res;
        }
    };