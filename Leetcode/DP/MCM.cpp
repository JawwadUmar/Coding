#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> &arr,vector<vector<int>> &dp){
    int n = arr.size();

    if(i ==j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int res = INT_MAX;

    for(int k = i; k<j; k++){

        int steps = f(i,k, arr, dp) + f(k+1, j, arr, dp) + arr[i-1]*arr[j]*arr[k];
        res = min(res, steps);
    }

    return dp[i][j]= res;
}


int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int> (n, -1));
    return f(1, n-1, arr, dp);
}