#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int r, c;
        r = c = 0;
        set<vector<int>> st (obstacles.begin(), obstacles.end());
        vector<vector<int>> dir = {{0,1}, {1, 0}, {0,-1}, {-1, 0}}; //NESW
        int currFacing = 0;
        int res= 0;
        for(int command : commands){
            if(command == -1){ //right
               currFacing+=1;
            }
            else if(command == -2){ //left
                currFacing-=1;
            }

            else{
                int nrow, ncol;
                nrow = r;
                ncol = c;
                for(int idx = 1; idx<=command; idx++){
                     if(st.find({ r + dir[currFacing][0]*idx, c + dir[currFacing][1]*idx}) != st.end()){
                        break;
                    }
                     nrow = r + dir[currFacing][0]*idx;
                     ncol = c + dir[currFacing][1]*idx;
                }

                r = nrow;
                c = ncol;
            }

            currFacing = (currFacing + 4)%4;
            cout<<r<<" "<<c<<endl;
            res = max(res, r*r + c*c);
        }

        return res;
    }
};