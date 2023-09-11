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

    if(n%2 == 0){
        
        cout<<2<<endl;

        cout<<1<<" "<<n<<endl;
        cout<<1<<" "<<n<<endl;

        return;
    }

    else{

        cout<<4<<endl;
        
        cout<<1<<" "<<n-1<<endl;
        cout<<1<<" "<<n-1<<endl;

        cout<<n-1<<" "<<n<<endl;
        cout<<n-1<<" "<<n<<endl;
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