#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int climbStairs(int idx, int n, vector<int>& costs) {
        if(idx == n-1){
            return 0;
        }
        
        int p1, p2, p3;
        p1 = p2 = p3 = 1e9;

        if(idx+1 < n){
            p1 = costs[idx+1] + 1 + climbStairs(idx+1, n, costs);
        }

        if(idx+2 < n){
            p2 = costs[idx+2] + 4 + climbStairs(idx+2, n, costs);
        }

        if(idx+3 < n){
            p3 = costs[idx+3] + 9 + climbStairs(idx+3, n, costs);
        }

        return min({p1, p2, p2});
    }

    int climbStairs(int n, vector<int>& costs) {
        return climbStairs(-1, n, costs);
    }
};