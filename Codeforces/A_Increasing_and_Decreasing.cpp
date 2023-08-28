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
    int x, y, n;
    cin>>x>>y>>n;

    vector<int> a(n);
    a[0] = x;
    a[n-1] = y;
    int cnt = 1;

    for(int i = n-2; i>=1; i--){
        a[i] = a[i+1] - cnt;
        cnt++;
    }

    if(n>= 3 && a[1] - a[0] <= a[2]-a[1]){
        cout<<-1<<endl;
        return;
    }

    for(auto it: a){
        cout<<it<<" ";
    }
    cout<<endl;
    
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