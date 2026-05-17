#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canReach(int idx, vector<int>& arr, set<int> &st, vector<int> &dp) {
        if(st.count(idx)){
            return true;
        }
        if(dp[idx] == 1){
            return false;
        }

        dp[idx] = 1;
        int nxtIndx1 = idx + arr[idx];
        int nxtIndx2 = idx - arr[idx];

        bool flag1 = false;
        bool flag2 = false;
        int n = arr.size();

        if(nxtIndx1 <n){
            flag1 = canReach(nxtIndx1, arr, st, dp);
        }
        if(nxtIndx2 >=0){
            flag2 = canReach(nxtIndx2, arr, st, dp);
        }

        return flag1 | flag2;
    }   

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> dp(n, 0);
        set<int> st;
        
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == 0){
                st.insert(i);
            }
        }

        return canReach(start, arr, st, dp);

    }
};