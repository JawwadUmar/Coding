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

void solve(){
    int n;
    cin>>n;

    vector<int> a(n-1);

    for(int i = 0; i<n-1; i++){
        cin>>a[i];
    }

    map<int, int> mpp;
    map<int, int> mp;
    if(a[0] <=n && a[0]>= 1){
        mp[a[0]]++;
    }

    else{
        mpp[a[0]]++;
    }

    for(int i = 1; i<a.size(); i++){
        int diff = a[i] - a[i-1];

        if(diff>=1 && diff<=n && mp[diff] ==0){
            mp[diff]++;
        }

        else{
            mpp[diff]++;
        }
        
    }

    int cnt = 0;
    int A = -1;
    int B = -1;
    for(int i = 1; i<=n; i++){
        if(!mp[i]){
            if(A==-1){
                A = i;
            }

            else{
                B = i;
            }
            cnt++;
        }
    }

    if(cnt> 2){
        cout<<"NO"<<endl;
    }

    else if(mpp.size() > 1){
        cout<<"NO"<<endl;
    }

    else if(cnt == 1){
        cout<<"YES"<<endl;
    }

    else{
        int target;
        for(auto it: mpp){
            target = it.first;
        }

        if(A+B == target){
            cout<<"YES"<<endl;
        }

        else{
            cout<<"NO"<<endl;
        }
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