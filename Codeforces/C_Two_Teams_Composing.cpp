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


bool f(int mid, map<int, int> &mp, set<int> &st){

    if(mid == 0){
        return true;
    }

    int mx = 0;

    if(st.size() < mid){
        return false;
    }

    int x = -1;

    for(auto it: mp){
        if(it.second > mx){
            mx = it.second;
            x = it.first;
        }
    }

    if(mx < mid){
        return false;
    }

    else if(mx == mid){

        if(st.size()-1 < mid){
            return false;
        }

        return true;
    }

    return true;
}


void solve(){

    int n;
    cin>>n;

    vector<int> a(n);
    map<int,int> mp;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }


    set<int> st (a.begin(), a.end());

    int low = 0;
    int high = st.size();
    int res = 0;

    while (high >= low)
    {
        int mid = (high+low)/2;

        if(f(mid, mp, st)){
            res = mid;
            low = mid+1;
        }

        else{
            high = mid-1;
        }
    }

    cout<<res<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}