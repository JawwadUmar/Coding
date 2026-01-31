#include <vector>
#include <set>
using namespace std;
typedef pair<int,int> Point;

class Rectangle{
    public:
        Point A;
        Point B;
        Point C;
        Point D;

        Rectangle(Point A, Point B, Point C, Point D){
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        }

        vector<Point> getAllPoints(){
            return {A, B, C, D};
        }

        long long findMaxFittingSquare(){
            long long diffx = C.first - A.first;
            long long diffy = C.second - A.second;

            return diffx*diffy;
        }
};

class Solution {
public:
    vector<Point>isOverlapping(Rectangle r1, Rectangle r2){
        int x_max = r1.C.first;
        int y_max = r1.C.second;

        int x_min = r1.A.first;
        int y_min = r1.A.second;

        vector<Point> points = r2.getAllPoints();
        vector<Point> res = r2.getAllPoints();

        for(Point p: points){
            int x = p.first;
            int y = p.second;

            if(x<=x_max && x>=x_min && y<=y_max && y>=y_min){
                res.push_back(p);
            }
        }

        return res;
    }

    long long findmaxSquare(Point A, Point C){
        int diffx = abs(C.first - A.first);
        int diffy = abs(C.second - A.second);

        return min(diffx*1ll*diffx, diffy*1ll*diffy);
    }

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long res = 0;

        for(int i =0; i<n; i++){
            int Ax = bottomLeft[i][0];
            int Ay = bottomLeft[i][1];

            int Cx = topRight[i][0];
            int Cy = topRight[i][1];

            Point A = {Ax, Ay};
            Point B = {Cx, Ay};
            Point C = {Cx, Cy};
            Point D = {Ax, Cy};

            Rectangle r1(A, B, C, D);

            for(int j = 0; j<n; j++){
                if(j == i){
                    continue;
                }

                int Px = bottomLeft[j][0];
                int Py = bottomLeft[j][1];

                int Rx = topRight[j][0];
                int Ry = topRight[j][1];

                Point P = {Px, Py};
                Point Q = {Rx, Py};
                Point R = {Rx, Ry};
                Point S = {Px, Py};

                Rectangle r2(P, Q, R, S);

                vector<Point> overlappingPoints = isOverlapping(r1, r2);
                
                if(overlappingPoints.empty()){
                    continue;
                }

                else if(overlappingPoints.size() == 1){
                    Point p = overlappingPoints[0];
                    if(p == P){
                        res = max(res, findmaxSquare(P, C));
                    }

                    else if(p == Q){
                        res = max(res, findmaxSquare(Q, D));
                    }

                    else if(p == R){
                        res = max(res, findmaxSquare(R, A));
                    }

                    else if(p == S){
                        res = max(res, findmaxSquare(S, B));
                    }
                }

                else if(overlappingPoints.size() == 2){
                    Point p1 = overlappingPoints[0];
                    Point p2 = overlappingPoints[1];
                    int p3x, p3y, p4x, p4y;

                    if(p1 == P && p2 == Q){
                        
                        p3y = p4y = C.second;
                        p3x = P.first;
                        p4x = Q.first;
                       

                        Point p3 = {p3x, p3y};
                        Point p4 = {p4x, p4y};

                        Rectangle r(p1, p2, p4, p3);

                        res = max(res, r.findMaxFittingSquare());

                    }

                    else if(p1 == P && p2 == S){
                        p3x = p4x = B.first;
                        p3y = P.second;
                        p4y = S.second;

                        Point p3 = {p3x, p3y};
                        Point p4 = {p4x, p4y};

                        Rectangle r(p1, p3, p4, p2);

                        res = max(res, r.findMaxFittingSquare());
                    }

                    else if(p1 == Q && p2 == R){
                        p3x = p4x = A.first;
                        p3y = R.second;
                        p4y = P.second;

                        Point p3 = {p3x, p3y};
                        Point p4 = {p4x, p4y};

                        Rectangle r(p4, p1, p2, p3);

                        res = max(res, r.findMaxFittingSquare());
                    }

                    else if(p1 == R && p2 == S){
                         p3y = p4y = A.second;
                         p3x = S.first;
                         p4x = R.first;

                        Point p3 = {p3x, p3y};
                        Point p4 = {p4x, p4y};

                        Rectangle r(p3, p4, p1, p2);

                        res = max(res, r.findMaxFittingSquare());
                    }
                }

                else{
                    res = max(res, r2.findMaxFittingSquare());
                }
            }
        }

        return res;
    }
};