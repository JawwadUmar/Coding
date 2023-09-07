#include <bits/stdc++.h>
using namespace std;    

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> distance(V, 1e8);
        distance[S] = 0;
        
        for(int i=0; i<V-1; i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt= it[2];
            
            if(distance[v] > wt + distance[u] && distance[u]!= 1e8){
                distance[v] =  wt + distance[u];
            }
        }
    }
    
    //check if there's a negative cycle
    //we will do relaxation one more time, ie run run iteration for the Vth time
    //if distance array decreases, then it has a negative cycle
    
    for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt= it[2];
            
            if(distance[v] > wt + distance[u] && distance[u]!= 1e8){
                return {-1};
            }
    }
    return distance;
    }
};
