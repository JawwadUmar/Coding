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

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    int ans = 0;
    bool flag = false;
    sort(a.begin(), a.end());
    int x;

    for(int i = 0; i<n; i++){
        if(a[i] == ans){
            ans++;
        }

        else if(flag == false){
            flag = true;
            x = ans;
            ans+=2;
        }

        else{
            break;
        }
    }

    cout<<x<<endl;

    set<int> st (a.begin(), a.end());

    // for(int i = 1; i<=n; i++){

    //     while (x>=0)
    //     {

    //     cout<<x<<endl;
    //     cout<<x-1<<endl;
    //     x = x-1;

    //     }

    //     if(x == -1){
    //         break;
    //     }

    // }
    
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