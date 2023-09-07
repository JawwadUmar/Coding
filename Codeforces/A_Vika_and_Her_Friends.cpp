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

bool sameParity(int x, int y, int r, int c){
    int A = r+c;
    int B = x+y;

    if(A%2 && B%2 || A%2 == 0 && B%2 == 0){
        return true;
    }

    return false;
}

void solve(){
    int n, m, k;
    cin>>n>>m>>k;

    int x, y;
    cin>>x>>y;

    bool flag = false;

    while (k--)
    {
        int xi, yi;
        cin>>xi>>yi;

        if(sameParity(x, y, xi, yi)){
            flag = true;
        }
    }

    if(flag){
        cout<<"NO"<<endl;
    }

    else{
        cout<<"YES"<<endl;
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