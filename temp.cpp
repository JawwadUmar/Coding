//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int calculate(int row, int col, int hop, vector<vector<int>> &mat){
    
    int n = mat.size();
    int m = mat[0].size();
    
    int sum = 0;
    
    vector<int> delrow = {-hop, 0, hop, 0, -hop, hop, hop, -hop};
    vector<int> delcol = {0, hop, 0, -hop, hop, hop, -hop, -hop};
    
    for(int i = 0; i<8; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        
        if(nrow>=0 && ncol >=0 && nrow <n && ncol <m){
            sum+= mat[nrow][ncol];
        }
    }
    
    return sum;
}

int calculate(int row, int col, int hop, vector<vector<int>> &mat, vector<vector<int>> &vis){
    
    vis[row][col] =1;
    
    if(hop == 0){
        return mat[row][col];
    }
    
    int n = mat.size();
    int m = mat[0].size();
    
    int sum = 0;
    
    vector<int> delrow = {-1, 0, 1, 0, -1, 1, 1, -1};
    vector<int> delcol = {0, 1, 0, -1, 1, 1, -1, -1};
    
    for(int i = 0; i<8; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        
        if(nrow>=0 && ncol >=0 && nrow <n && ncol <m && vis[nrow][ncol] == 0) {
            sum+= calculate(nrow, ncol, hop-1, mat, vis);
        }
    }
    
    return sum;
}


    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        
    vector<int> res;
    vector<int> delrow = {-1, 0, 1, 0, -1, 1, 1, -1};
    vector<int> delcol = {0, 1, 0, -1, 1, 1, -1, -1};
        
        for(int i = 0; i<q; i++){
            int hop = queries[i][0];
            int row = queries[i][1];
            int col = queries[i][2];
            
            if(hop ==1){
            int x = calculate(row, col, hop, mat);
            res.push_back(x);
            continue;
            
            }
            
            vector<vector<int>> vis (n, vector<int> (m, 0));
            int x = 0;
            
            for(int i = 0; i<8; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
        
          if(nrow>=0 && ncol >=0 && nrow <n && ncol <m) {
           
           vis[nrow][ncol] = 1;
         }
        }
            
            
            
            for(int i = 0; i<8; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
        
        if(nrow>=0 && ncol >=0 && nrow <n && ncol <m) {
            x+= calculate(nrow, ncol, hop-1, mat, vis);
        }
        }
        
        res.push_back(x);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends