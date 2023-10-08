#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int binaryExponentiation(int x, int p){
    int res = 1;
    while(p){
        if(p%2){
            res = (res * x);
        }

        x = (x*x);
        p = p/2; 
    }
    
    return res;
}

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}


void solve(){

    int n, m;
    cin>>n>>m;

    int rem = n%m;

    if(rem == 0){
        cout<<0<<endl;
        return;
    }

    int hcf = __gcd(rem, m);

    int nrem = rem/hcf;
    int nm = m/hcf;

    if(numberOfSetBits(nm) !=1){
        cout<<-1<<endl;
        return;
    }

    int res = 0;

    while (rem!= 0)
    
    {
        res+= rem;
        rem = rem*2;
        rem = rem%m;
 
        if(rem == 0){
            break;
        }
    }


    cout<<res<<endl;
    return;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}