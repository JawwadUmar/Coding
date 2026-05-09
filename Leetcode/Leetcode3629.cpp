#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

     static unordered_map<int, vector<int>> &GetAllPrimeFactors(){
        
        static unordered_map<int, vector<int>> factors;

        if(!factors.empty()){
            return factors;
        }

        for(int i = 2; i<=1e6; i++){
            if(factors[i].size()==0){
                for(int j = i; j<=1e6; j+=i){
                    factors[j].push_back(i);
                }
            }
        }

        return factors;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1){
            return 0;
        }
        
        auto &allPrimeFactors = GetAllPrimeFactors();

        vector<int> adj[n];
        unordered_map<int, vector<int>> primeAdj;

        for(int i = 0; i<n-1; i++){
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }

        // for(int i = 0; i<n; i++){
        //     cout<<i<<"-> ";
        //     for(int node: adj[i]){
        //         cout<<node<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i = 0; i<n; i++){
            for(int p: allPrimeFactors[nums[i]]){
                primeAdj[p].push_back(i);
            }
        }

        vector<int> vis(n, 0);
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = 1;

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int node = p.first;
            int dis = p.second;

            for(int adjNodes: adj[node]){
                if(!vis[adjNodes]){
                    if(adjNodes == n-1){
                        return dis+1;
                    }

                    vis[adjNodes] = 1;
                    q.push({adjNodes, dis+1});
                }
            }

            if(allPrimeFactors[nums[node]].size() == 1){
                //it is a prime number
                int p = nums[node];

                for(int adjNode: primeAdj[p]){
                    if(!vis[adjNode]){
                        if(adjNode == n-1){
                            return dis+1;
                        }

                        vis[adjNode] = 1;
                        q.push({adjNode, dis+1});
                    }
                }

                primeAdj[p].clear();
            }
        }

        return -1;
        
    }
};