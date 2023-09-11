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

bool isPrime(int number) {
    // Handle special cases
    if (number <= 1) {
        return false;
    }
    
    // Check for divisibility from 2 to the square root of the number
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    
    // If no divisors are found, the number is prime
    return true;
}

int Divisor(int n){
    for(int i =2; i*i<=n; i++){
        if(n%i ==0){
            return i;
        }
    }

    return -1;
}


void solve(){
    int l, r;
    cin>>l>>r;

    if(l>r){
        cout<<-1<<endl;
        return;
    }

    if(r==2 || r==3 || r==1){
        cout<<-1<<endl;
        return;
    }

    if(l==r){

        if(isPrime(l) || l ==1 || l==2){
            cout<<-1<<endl;
            return;
        }

        else if(r%2 ==0){
            cout<<r/2<<" "<<r/2<<endl;
            return;
        }

        else{
            int x =Divisor(l);
            // cout<<x<<endl;
            cout<<x<<" "<<l-x<<endl;
            return;

        }
    }

   if(r%2 ==0){
        cout<<r/2<<" "<<r/2<<endl;
    }

    else{
        r = r-1;
        cout<<r/2<<" "<<r/2<<endl;
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