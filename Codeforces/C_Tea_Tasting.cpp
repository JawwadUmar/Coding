#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

void solve(){

    int n;
    cin>>n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    for(int i = 0; i<n; i++){
        cin>>b[i];
    }


    vector<int> prefSum (n);
    prefSum[0] = b[0];

    for(int i = 1; i<n; i++){
        prefSum[i] = b[i] + prefSum[i-1];
    }

    vector<int> res (n, 0);
    vector<int> temp(n, 0);

    for(int i = 0; i<n; i++){

        int x = i-1>=0 ? prefSum[i-1] : 0;

        auto it = upper_bound(prefSum.begin(), prefSum.end(), a[i]+x);
        int idx = it - prefSum.begin();
        // cout<<idx<<endl;

        if(it == prefSum.end()){
            res[i]+=1;
            continue;
        }

        else{
            int y = idx-1>=0 ? prefSum[idx-1] : 0;
            int rem = a[i] - y + x;
            temp[idx]+=rem;

            res[idx]-=1;
            res[i]+=1;
            
        }
    }


    for(int i = 1; i<n; i++){
        res[i] = res[i] + res[i-1];
    }

    for(int i = 0; i<n; i++){
        res[i] = res[i]*b[i];
        res[i]+= temp[i];

        cout<<res[i]<<" ";
    }

    cout<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}