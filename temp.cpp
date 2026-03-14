#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int LIMIT;
    int MOD = 1e9+7;
    int dp[202][202][202][3];

    long long numberOfStableArrays(int cnt0, int cnt1, int limit, int flag) {
        if(cnt0 <0 || cnt1 < 0 || limit < 0){
            return 0;
        }

        if(cnt0 == 0 && cnt1 == 0){
            return 1;
        }

        if(dp[cnt0][cnt1][limit][flag+1] != -1){
            return dp[cnt0][cnt1][limit][flag+1];
        }

        if(flag == -1){
           return dp[cnt0][cnt1][limit][flag+1] =  numberOfStableArrays(cnt0-1, cnt1, limit-1, 0) + numberOfStableArrays(cnt0, cnt1-1, limit-1, 1);
        }

        long long p1, p2, p3, p4;
        p1 = p2 = p3 = p4 = 0;

        if(flag == 0){
            p1 = numberOfStableArrays(cnt0-1, cnt1, limit-1, 0);
            p2 = numberOfStableArrays(cnt0, cnt1-1, LIMIT-1, 1);
        }

        else{
            p3 = numberOfStableArrays(cnt0-1, cnt1, LIMIT-1, 0);
            p4 = numberOfStableArrays(cnt0, cnt1-1, limit-1, 1);
        }

        return dp[cnt0][cnt1][limit][flag+1]= (p1 + p2 + p3 + p4)%MOD;
        
    }
public:
    int numberOfStableArrays(int cnt0, int cnt1, int limit) {
        LIMIT = limit;
        memset(dp, -1, sizeof(dp));
        return numberOfStableArrays(cnt0, cnt1, limit, 0);
    }
};