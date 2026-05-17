#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001];
     int maximumJumps(int idx, vector<int>& nums, int target) {
        int n = nums.size();
        if(idx == n-1){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int res = -1e9;
        for(int i = idx+1; i<n; i++){
            if(abs(nums[idx] - nums[i]) <= target){
                int temp =  maximumJumps(i, nums, target);
                if(temp == -1e9){
                    continue;
                }
                res = max(res, 1 + temp);
            }
        }

        return dp[idx] =  res;
     }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp)); 
        int res = maximumJumps(0, nums, target);

        return res == -1e9 ? -1 : res;
    }
};