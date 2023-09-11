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

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    int x;
    bool flag = true;

    for(int i  =0 ;i<n; i++){
        cin>>a[i];
        if(i == 0){
            x = a[i];
            continue;
        }

        else{
            if(a[i]%x != 0){
                flag = false;
            }
        }
    }

    if(flag){
        cout<<"YES"<<endl;
    }

    else{
        cout<<"NO"<<endl;
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