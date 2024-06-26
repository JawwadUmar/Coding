#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    
	    int n = matrix.size();
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] ==-1){
	                matrix[i][j] = 1e9;
	            }
	            
	            if(i==j){
	                matrix[i][j] = 0;
	            }
	        }
	    }
	    
	    //we we go to every node, via every node
	    for(int via=0; via<n; via++){
	        
	        for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            
	            matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
	            
	    }
	    }
	    }
	    
	    
	    //check if there's a negative cycle 
	    for(int i=0; i<n; i++){
	        if(matrix[i][i] <0){
	            //negative cycle exists
	            return;
	        }
	    }
	    
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] ==1e9){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	    
	    
	}
};