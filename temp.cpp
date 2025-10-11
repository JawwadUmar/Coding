#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        multiset<vector<int>> mst;

        for(int i = 0; i<n; i++){
            vis[i][0] = 1;
            vis[i][m-1] = 1;

            mst.insert({heightMap[i][0], i, 0});
            mst.insert({heightMap[i][m-1], i, m-1});
        }

        for(int i = 1; i<m-1; i++){
            vis[0][i] = 1;
            vis[n-1][i] = 1;

            mst.insert({heightMap[i][0], 0, i});
            mst.insert({heightMap[i][m-1], n-1, i});
        }

        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        int res = 0;

        while (!mst.empty())
        {
            auto it = mst.begin();
            vector<int> temp = *it;
            mst.erase(it);

            int h = temp[0];
            int r = temp[1];
            int c = temp[2];

            for(int i = 0; i<4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    mst.insert({heightMap[nrow][ncol], nrow, ncol});

                    if(heightMap[nrow][ncol] < h){
                        res+= h - heightMap[nrow][ncol];
                    }
                }
            }
        }

        return res;
        
    }
};