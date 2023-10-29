#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int MOD = 1e9+7;

int f(int idx, int n, vector<int> &dp){
    
    if(idx == n){
        return 1;
    }
    
    if(idx > n){
        return 0;
    }

    if(dp[idx] != -1){
        return dp[idx];
    }

    int p1, p2, p3, p4, p5, p6;
    p1 = p2 = p3 = p4 = p5 = p6 = 0;

    p1 = f(idx+1, n, dp);
    p2 = f(idx+2, n, dp);
    p3 = f(idx+3, n, dp);
    p4 = f(idx+4, n, dp);
    p5 = f(idx+5, n, dp);
    p6 = f(idx+6, n, dp);

    return dp[idx] = (p1+p2+p3+p4+p5+p6)%MOD;
}

signed main(){
    
    int n;
    cin>>n;

    vector<int> dp(n+1, -1);

    cout<<f(0, n, dp)<<endl;


}