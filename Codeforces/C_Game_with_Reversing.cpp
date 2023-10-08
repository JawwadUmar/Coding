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

    string a, b;
    cin>>a>>b;

    string temp = b;
    reverse(temp.begin(), temp.end());

    int cnt1 = 0;
    int cnt2= 0;

    for(int i = 0; i<n; i++){

        if(a[i] != b[i]){
            cnt1++;
        }

        if(a[i] != temp[i]){
            cnt2++;
        }
    }

    if(cnt1 == 0){
        cout<<0<<endl;
        return;
    }

    if(cnt2 == 0){
        cnt2 = 1;
    }

    

    cout<<min(2*cnt2, 2*cnt1-1)<<endl;
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