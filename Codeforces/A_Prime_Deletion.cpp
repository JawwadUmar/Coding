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

bool isPrime(int n){
    
    if(n ==1){
        return false;
    }

    if(n ==2){
        return true;
    }

    if(n == 3){
        return true;
    }

    for(int i = 2; i*i<=n; i++){
        if(n%i ==0){
            return false;
        }
    }

    return true;
}

void solve(){
    
    string s;
    cin>>s;

    
    // for(int i = 1; i<s.size(); i++){
    //     int b = s[i] - '0';

    //     int num = a*10 + b;

    //     if(isPrime(num)){
    //         cout<<num<<endl;
    //         return;
    //     }

    //     a = b;
    // }

    for(int i = 0; i<s.size(); i++){
        int a = s[i] - '0';
        for(int j=i+1; j<s.size(); j++){
            int b = s[j] - '0';

            int num = a*10 + b;

            if(isPrime(num)){
                cout<<num<<endl;
                return;
            }
        }
    }

    cout<<-1<<endl;
    return;
    
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