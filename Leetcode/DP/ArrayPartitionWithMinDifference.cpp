#include <bits/stdc++.h>
using namespace std;


bool f(int idx, int currSum, vector<int>& arr, vector<vector<int>> &dp){
	
	int n = arr.size();
	
	if(idx == n){
		if(currSum == 0){
			return true;
		}
		return false;
	}

	if(currSum<0){
		return false;
	}

	if(dp[idx][currSum] != -1){
		return dp[idx][currSum];
	}

	bool take = f(idx+1, currSum-arr[idx], arr, dp);
	bool not_take = f(idx+1, currSum, arr, dp);

	return dp[idx][currSum] =  take | not_take;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;

	for(auto it: arr){
		sum+=it;
	}
	
	int target = sum/2;
	
	vector<vector<int>> dp(n+1, vector<int> (target+1, -1));


	//Populate the dp array :)
	for(int i = 0; i<=target; i++){
		f(0, i, arr, dp);
	}

	int res = INT_MAX;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<= target; j++){
			if(dp[i][j] == 1){
				res = min(res, abs((sum - j) - j));
			}
		}
	}
	
	return res;
}
