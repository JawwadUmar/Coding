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

    vector<int> a(n, 0);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());

    vector<int> suff(n+1, 0);

    for(int i = n-1; i>=0; i--){
        suff[i] = a[i] + suff[i+1];
    }

    suff.pop_back();

    for(auto it: a){
        cout<<it<<" ";
    }
    cout<<endl;

    for(auto it: suff){
        cout<<it<<" ";
    }

    cout<<endl;

    int cnt = 0;

    for(int i = 0; i<n; i++){

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