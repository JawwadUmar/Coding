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
    int n, m;
    cin>>n>>m;

    if(m == 1){
        cout<<n<<endl;
        return;
    }

    if(n == 1){
        cout<<2<<endl;
        return;
    }

    int res = min(m, n+1);

    cout<<res<<endl;
    vector<vector<int>> mat(n, vector<int> (m));


    if(m>= n+1){
        
    }

    else{

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