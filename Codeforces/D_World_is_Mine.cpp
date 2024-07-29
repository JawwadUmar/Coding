#include <bits/stdc++.h>
using namespace std;

#define int long long


int f(int idx, vector<int>&v){
    int n = v.size();

    if(idx >= n-1){
        return 0;
    }

    int res = 0;
    for(int i = idx+1; i<n; i++){
        if(v[i] <= i-idx){
            res = max(res, 1 + f(idx+1, v));
        }
    }

    return res;

}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    
    map<int, int> mp;

    for(int i = 1; i<=n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    vector<int> v;
    for(auto it: mp){
        v.push_back(it.second);
    }

    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<mp.size() - f(0, v)<<endl;
}

signed main(){
    int t;
    cin>>t;

    while (t--)
    {
        solve();
    }

    
}