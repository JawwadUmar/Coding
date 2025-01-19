#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long






//ctrl shift B for output

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}


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

int factorial(int n, vector<int> &fac){
    if(n<=2){
        return n;
    }

    if(fac[n] != -1){
        return fac[n];
    }

    return (n*factorial(n-1, fac))%MOD;
}


int distanceSum(int m, int n, int k) {

    vector<int> fac(n*m+1, -1);
    int numerator = factorial(m*n -2, fac);
    int B = factorial(k-2, fac);
    int C = factorial(m*n -2 - (k-2), fac);

    int denominator = (B*C)%MOD;

    int ncr = (numerator*binaryExponentiation(denominator, MOD-2))%MOD;
    int x = (((((n*n)%MOD*m)%MOD*((m*m)%MOD-1))%MOD))%MOD;
    int y = (((((m*m)%MOD*n)%MOD*((n*n)%MOD-1))%MOD))%MOD;

    return (((x+y)*ncr)%MOD * binaryExponentiation(6, MOD-2))%MOD;

}

void solve(){

    
    
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