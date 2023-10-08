#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
int binaryExponentiation(int x, int p){\
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


int f(vector<set<int>> &v, int elem){
    //without elem
    set<int> st;

    for(int i = 0; i<v.size(); i++){
        if(v[i].find(elem) == v[i].end()){
            for(auto it: v[i]){
                st.insert(it);
            }
        }
    }

    return st.size();
}



void solve(){
    int n;
    cin>>n;

    vector<set<int>> v;

    // vector<set<int>> v2;



    set<int> vis;

    map<int, int> mp;

    int mxSize = INT_MIN;


    for(int i = 0; i<n; i++){
        
        int k;
        cin>>k;

        mxSize = max(mxSize, k);

        set<int> st;


        for(int j = 0; j<k; j++){
            int x;
            cin>>x;

            // cout<<x<<endl;

            mp[x]++;
            vis.insert(x);
            st.insert(x);
        }

        v.push_back(st);
    }

    if(n == 1 || v.size() == 1){
        cout<<0<<endl;
        return;
    }

    int res = INT_MIN;

    for(auto elem: vis){

        res = max(res, f(v, elem));
    }


    cout<<res<<endl;

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