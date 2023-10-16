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

    int x = n;

    x = x-1;
    x = x-2;

    if(x%3 != 0){
        if(x>0){
            if(x!= 1 && x!= 2){
                cout<<"YES"<<endl;
                cout<<1<<" "<<2<<" "<<x<<endl;
                return;
            }
        }
    }

    x = n;

    x= x-1;
    x= x-4;

    if(x%3 != 0){
        if(x>0){
            if(x!= 1 && x!= 4){
                cout<<"YES"<<endl;
                cout<<1<<" "<<4<<" "<<x<<endl;
                return;
            }
        }
    }

    cout<<"NO"<<endl;
    
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}