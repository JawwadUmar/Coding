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


void solve(){

    int n;
    cin>>n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    if(a[0] == 1){
        b[0] = 2;
    }

    else{
        b[0] = 1;
    }

    for(int i = 1; i<n; i++){
        int p1 = b[i-1]+1;

        if(a[i] != p1){
            b[i] = p1;
        }  

        else{
            b[i] = p1+1;
        }  
    }


    cout<<b.back()<<endl;
    
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