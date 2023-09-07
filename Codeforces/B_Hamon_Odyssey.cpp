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

    for(int i= 0; i<n; i++){
        cin>>a[i];
    }

    int ans = 0;
    
    int first = a[0];
    int curr = INT_MAX;

    for(int i = 0; i<n; i++){

        curr = curr&a[i];

        if(curr == 0){
            ans++;
            curr = INT_MAX;
        }
    }

    if(ans == 0){
        cout<<1<<endl;
    }

    else{
        cout<<ans<<endl;
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