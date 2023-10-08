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
    int n;
    cin>>n;

    bool flag = true;
    int ans = -1;
    int end = -1;

    for(int i = 0; i<n; i++){
        int s, e;
        cin>>s>>e;

        if(i ==0){
            ans = s;
            end = e;
            continue;
        }

        if(s>= ans && e>=end){
            flag = false;
        }
    }

    if(flag){
        cout<<ans<<endl;
    }

    else{
        cout<<-1<<endl; 
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