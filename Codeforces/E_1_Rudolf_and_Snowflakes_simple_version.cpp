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

bool flag(int n){

    int D = 1 + 4*(n-1);

    int d = sqrtl(D);
    
    if(d*d !=D){
        return false;
    }

    if((d-1)%2 != 0){
        return false;
    }

    int r = (d-1)/2;

    if(r<=1){
        return false;
    }

    return true;
}

void solve(){
    int n;
    cin>>n;

    if(n<7){
        cout<<"NO"<<endl;
        return;
    }

    if(flag(n)){
        
        cout<<"YES"<<endl;
        return;
    }



    for(int a = 2; a<=1000000; a++){

        int r = n*(a-1);

        r+= 1;

        if(r%a != 0){
            continue;
        }

        r = (double) r;

        double terms = log10(r)/(log10(a));
        terms = ceil(terms);

        if(terms<3){
            continue;
        }

        int x = binaryExponentiation(a, terms);
        
        if(x == r && terms>=3){
            cout<<"YES"<<endl;
            return;
        }

        terms-= 1;

        if(terms<3){
            continue;
        }

        x = binaryExponentiation(a, terms);

        if(x == r && terms>=3){
            cout<<"YES"<<endl;
            return;
        }

    }

    cout<<"NO"<<endl;
    
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