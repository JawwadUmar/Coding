#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isOverlapping(int Ax, int Ay, int Cx, int Cy, int Px, int Py, int Rx, int Ry){
        //if C is captured
        
        if(Cx >= Px && Cx<=Rx && Cy>=Py && Cy<=Ry){
            return true;
        }

        int Dx = Ax;
        int Dy = Cy;

        if(Dx >= Px && Dx <= Rx && Dy>=Py && Dy<=Ry){
            return true;
        }

        return false;
    }

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long res = 0;

        for(int i =0; i<n; i++){
            int Ax = bottomLeft[i][0];
            int Ay = bottomLeft[i][1];

            int Cx = topRight[i][0];
            int Cy = topRight[i][1];
            

            for(int j = 0; j<n; j++){
                int Px = bottomLeft[j][0];
                int Py = bottomLeft[j][1];

                int Rx = topRight[j][0];
                int Ry = topRight[j][1];

                if(isOverlapping(Ax, Ay, Cx, Cy, Px, Py, Rx, Ry)){

                    if(Ax<Px && Cy<Ry){
                        //DOWN LEFT
                        //P -> bottom left
                        //C --> top right
                        long long diffx = Cx-Px;
                        long long diffy = Cy-Py;

                        res = max({res, min(diffx, diffy)});
                    }

                    else if(Ax>Px && Cy<Ry){
                        //DOWN RIGHT
                        //D--> top left
                        //Q--> bootom right

                        long long diffx = Rx - Ax;
                        long long diffy = Cy - Py;

                         res = max({res, min(diffx, diffy)});

                    }
                }
            }
        }

        return res*res;
    }
};