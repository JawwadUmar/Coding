//1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

int MOD = 1e9 + 7;

long long f(int idx, int mx, int len, int n , int m, int k,  vector<vector<vector<int>>>& dp){

    if(idx == n){
        if(len == k){
            return 1;
        }

        return 0;
    }

    if(len > k){
        return 0;
    }

    if(dp[idx][mx][len] != -1){
        return dp[idx][mx][len];
    }

    long long res = 0; 

    for(int i = 1; i<=m; i++){
        long long take;

        if(i>mx){
            take = f(idx+1, i, len+1, n, m, k, dp);
        }

        else{
            take = f(idx+1, mx, len, n, m, k, dp);
        }

        res = (res+take)%MOD;
    }

    return dp[idx][mx][len] = res%MOD;
}
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int>(k+1, -1)));
        return f(0, 0, 0, n, m, k, dp);
    }
};