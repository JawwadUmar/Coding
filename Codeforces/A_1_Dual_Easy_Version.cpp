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

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> res;

    vector<int> a(n);
    int mx = -21;
    int mn = 21;
    int sum = 0;
    map<int, int> mp;
    
    for(int i= 0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);

        mp[a[i]] = i;
    }

    if(mx == mn){
        cout<<0<<endl;
        return;
    }

    if(sum >= 0){
        //make all positive
        for(int i = 0; i<n; i++){
            while(a[i] <= 0){
                a[i]+= mx;
                // insert_in_res(a);
                res.push_back({i+1, mp[mx]+1});
                if(a[i] > mx){
                    mx = a[i];
                }
            }
        }

        for(int i = 1; i<n; i++){
        if(a[i] > a[i-1]){
            continue;
        }

        while (a[i] < a[i-1])
        {
            a[i]+= a[i-1];
            // insert_in_res(a);
            res.push_back({i+1, i});
        }
    }
    }

    else{
        //make all negative
        for(int i = 0; i<n; i++){
            while (a[i] >=0)
            {
                a[i]+=mn;
                res.push_back({i+1, mp[mn]+1});
                // insert_in_res(a);
            }
            
        }

        for(int i = n-2; i>=0; i--){
            if(a[i+1] > a[i]){
                continue;
            }

            while (a[i+1] < a[i])
            {
                a[i]+= a[i+1];
                res.push_back({i+1, i+1+1});
                // insert_in_res(a);
            }
            
        }
    }

    cout<<res.size()<<endl;

    for(int i = 0; i<res.size(); i++){
        vector<int> v = res[i];

        for(auto it: v){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    // t=1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}