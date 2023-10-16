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

    int n, a, b;
    cin>>n>>a>>b;

    string res = "";

    for(int i = 0; i<b; i++){
        res+= 'a' + i;
    }

    string temp = res;
    int x = res.size();
    
    int req = n-x;

    int j = req/x;
    int rem = req%x;

    while (j--)
    {
        res = res+temp;
    }

    res+= temp.substr(0, rem);

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