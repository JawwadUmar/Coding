#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

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

    int x = 2*n;

    vector<int> a(x);

    for(int i = 0; i<x; i++){
        cin>>a[i];
    }

    vector<pair<int, int>> v;

    sort(a.begin(), a.end());

    int i = 0;
    int j = a.size()-1;

    v.push_back({a[i], a[j]});
    i++;
    j--;

    int res = 0;

    // cout<<res<<endl;

    while (j>i)
    {
        int prevx = v.back().first;
        int prevy = v.back().second;

        res+= abs(a[i]-prevx) + abs(a[j]-prevy);

        v.push_back({a[i], a[j]});
        i++;
        j--;
    }

    cout<<res<<endl;

    for(auto it: v){
        cout<<it.first<<" "<<it.second<<endl;
    }
    
    
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