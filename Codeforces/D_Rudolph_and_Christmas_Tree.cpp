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
    double n, d, h;
    cin>>n>>d>>h;

    vector<double> y(n);

    for(int i = 0; i<n; i++){
        double x;
        cin>>x;
        y[n-1-i] = x;
    }

    double res = (d*h);

    for(int i = 1; i<n; i++){
        if(y[i] + h <= y[i-1]){
            res+= d*h;
        }

        else{
            double delta = y[i-1]-y[i];
            double x = ((d * (h -delta)))/h;

            res+= (d+x)*delta;
        }
    }

    res = res/2;

    cout<< fixed << setprecision(7)<< res<<endl;
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