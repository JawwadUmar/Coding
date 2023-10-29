#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
int binaryExponentiation(int x, int p){
    int res = 1;
    while(p){
        if(p%2){
            res = (res * x)%MOD;
        }

        x = (x*x)%MOD;
        p = p/2;
    }
    
    return res;
}

//ctrl shift B for output

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}


void solve(){

    int n;
    cin>>n;

    vector<int> arrival;
    vector<int> leaving;

    while (n--)
    {
        int a, b;
        cin>>a>>b;

        arrival.push_back(a);
        leaving.push_back(b);
    }

    sort(arrival.begin(), arrival.end());
    sort(leaving.begin(), leaving.end());

    // for(auto it: leaving){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    int i = 1;
    int j = 0;

    int cnt = 1;
    int res = 1;

    n = arrival.size();

    while (i<n)
    {
        while (i<n && arrival[i] < leaving[j])
        {
            cnt++;
            i++;
        }

        res = max(res, cnt);
        j++;
        cnt--;
    }

    cout<<res<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}