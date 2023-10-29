#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 998244353;
#define endl '\n'


void solve(vector<int> &dp){

    string s;
    cin>>s;

    int n = s.size();

    vector<string> v;
    int i = 0;

    while (i<n)
    {
        char c = s[i];
        string temp = "";

        while (i<n && s[i] == c)
        {
            temp+= c;
            i++;
        }
        
        v.push_back(temp);
    }

    int ans1 = 0;
    int ans2 = 1;
    for(auto it: v){
        ans1+= it.length() -1;
        ans2 = (ans2*it.length())%MOD;
    }

    int k = v.size();
    ans2 = (ans2*dp[n-k])%MOD;


    cout<<ans1<<" "<<ans2<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    vector<int> dp(200001, 1);

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i<=200000; i++){
        dp[i] = (i*dp[i-1])%MOD;
    }
    
    int t = 1;
    cin>>t;
    while(t--){
       solve(dp);
    }
    return 0;
}