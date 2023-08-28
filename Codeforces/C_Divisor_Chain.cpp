#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
int binaryExponentiation(int x, int p){
    int v1 = 1;
    while(p){
        if(p%2){
            v1 = (v1 * x)%MOD;
        }

        x = (x*x)%MOD;
        p = p/2;
    }
    
    return v1;
}

void solve(){
    int n;
    cin>>n;

    vector<int> v1;
    int itr = 1;

    while (itr< n)
    {
        v1.push_back(itr);
        itr = itr*2;
    }

    if(itr == n){
        v1.push_back(itr);
        cout<<v1.size()<<endl;

        reverse(v1.begin(), v1.end());

        for(auto it: v1){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }

    // cout<<"fnjnf"<<endl;
    itr = itr/2;

    int diff = n - itr;


    vector<int> v2;
    int pw = 1;

    while (diff>0)
    {
        if(diff%2){
            v2.push_back(pw);
        }

        pw = pw*2;
        diff = diff/2;
    }


    vector<int> res;
    res.push_back(n);
    int curr = n;

    for(int i = 0; i<v2.size(); i++){
        res.push_back(curr - v2[i]);
        curr = curr-v2[i];
    }

    res.pop_back();

    reverse(v1.begin(), v1.end());

    for(auto it: v1){
        res.push_back(it);
    }

    cout<<res.size()<<endl;

    for(auto it: res){
        cout<<it<<" ";
    }
    cout<<endl;


    
    
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