#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    int findSum(int l, int r, vector<int>& prefSum){
        if(l == 0){
            return prefSum[r];
        }

        return prefSum[r] - prefSum[l-1];
    }

    int f(int idx, int l, int r, vector<int>& stoneValue, vector<int> &prefSum, vector<vector<vector<int>>> &dp){
        if(l == r){
            return 0;
        }
        if(idx >= r){
            return -1e9;
        }

        int p1, p2;
        p1 = p2 = -1e9;

        //don't make a partition at idx
        p1 = f(idx+1, l, r, stoneValue,prefSum, dp);

        //make a partition at idx
        int sumLeft = findSum(l, idx, prefSum);
        int sumRight = findSum(idx+1, r, prefSum);

        if(sumLeft > sumRight){
            p2 = sumRight +f(idx+1, idx+1, r, stoneValue,prefSum,  dp) ;
        }
        else if(sumLeft < sumRight){
            p2 = sumLeft + f(l, l, idx, stoneValue,prefSum, dp);
        }
        else{
            p2 = max(sumRight + f(idx+1, idx+1, r, stoneValue,prefSum, dp), sumLeft + f(l, l, idx, stoneValue, prefSum, dp));
        }
        return max(p1, p2);
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefSum(n, 0);
        prefSum[0] = stoneValue[0];
        for(int i = 1; i<n; i++){
            prefSum[i] = prefSum[i-1] + stoneValue[i];
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n,-1)));
        return f(0, 0, n-1, stoneValue,prefSum, dp);
    }
};