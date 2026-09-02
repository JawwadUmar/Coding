#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int collectNearestLitter(vector<string>& classroom, int &startRow, int &startCol, int &energy, set<pair<int, int>> &litterPositions){
        int n = classroom.size();
        int m = classroom[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        queue<vector<int>> q;
        q.push({startRow, startCol, energy});
        vis[startRow][startCol] = 1;
        int moves = 0;

        while (!q.empty()) {
            int qsize = q.size();

            for (int i = 0; i < qsize; i++) {
                vector<int> qfront = q.front();
                int row = qfront[0];
                int col = qfront[1];
                int currentEnergy = qfront[2];
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];

                    if(nrow <n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol] == 0){
                        cout<<nrow<<" "<<ncol<<" "<<currentEnergy;
                    }

                    if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && classroom[nrow][ncol] != 'X' && vis[nrow][ncol] == 0 && currentEnergy > 0) {
                        vis[nrow][ncol] = 1;
                        if (classroom[nrow][ncol] == 'R'){
                            q.push({nrow, ncol, energy});
                        }
                        else{
                            q.push({nrow, ncol, currentEnergy - 1});
                        }
                            

                        if (classroom[nrow][ncol] == 'L') {
                            litterPositions.erase({nrow, ncol});
                            classroom[nrow][ncol] = '.';
                            energy = currentEnergy-1;
                            startRow = nrow;
                            startCol = ncol;
                            return moves +1;
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }

    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();
        int startRow, startCol;
        startRow = startCol = -1;
        set<pair<int, int>> litterPositions;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') {
                    startRow = i;
                    startCol = j;
                }
                if (classroom[i][j] == 'L') {
                    litterPositions.insert({i, j});
                }
            }
        }

        

        int res = 0;

        while (!litterPositions.empty())
        {
            int x = collectNearestLitter(classroom, startRow, startCol, energy, litterPositions);
            if(x == -1){
                return -1;
            }

            res+= x;
        }

        return res;
        
    }
};