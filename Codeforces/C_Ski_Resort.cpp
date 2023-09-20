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

int f(int cnt, int k){
    
    //k to cnt tk ka sum
    
    int n = cnt-k+1; //no of terms 
    int sum  = (n*(cnt+k))/2;

    return n*cnt - sum + n;

}

void solve(){
    int n, k, q;
    cin>>n>>k>>q;

    int res= 0;
    vector<int> a(n);
    int cnt = 0;
    map<int, int> mp;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(a[i] <= q){
            cnt++;
        }

        else{
            if(cnt>=k){
                // cout<<cnt<<endl;
                res+= f(cnt, k);
            }
            cnt = 0;
        }
    }

    if(cnt>= k){
        // cout<<cnt<<endl;
        res+= f(cnt, k);
    }

    cout<<res<<endl;

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