#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        
        int n = adj.size();
        queue<pair<int,int>> q;
        set<pair<int, int>> vis;

        for(int i = 0; i<n; i++){
            int node = i;
            int mask = 1<<i;

            q.push({node, mask});
            vis.insert({node, mask});
        }

        int target = (1<<n) -1;

        int ans = 0;
        

        while(!q.empty()){

            int n = q.size();
            for(int i = 0; i<n; i++){
                int node = q.front().first;
                int mask = q.front().second;
                q.pop();

                if(mask == target){
                    cout<<"reached"<<endl;
                    return ans;
                }

                for(auto it: adj[node]){

                    int mask_it = 1<<it;
                    int newMask = mask | mask_it;

                    if(vis.count({it, newMask})==0){
                        
                        vis.insert({it, newMask});
                        q.push({it, newMask});
                    }
                }
            }
            cout<<n<<endl;
            ans++;
        }

        return ans;
    }
};