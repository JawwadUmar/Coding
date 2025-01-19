#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
long long MOD = 1e9+7;

long long binaryExponentiation(long long x, long long p){
    long long res = 1;
    while(p){
        if(p%2){
            res = (res * x)%MOD;
        }

        x = (x*x)%MOD;
        p = p/2;
    }
    
    return res;
}


long long factorial(long long n, vector<long long> &fac){

    if(n==0){
        return 1;
    }

    if(fac[n] != -1){
        return fac[n];
    }

    return (n*factorial(n-1, fac))%MOD;
}


int distanceSum(int M, int N, int K) {

    
    long long m = M;
    long long n = N;
    long long k = K;

    vector<long long> fac(n*m+1, -1);
    long long numerator = factorial(m*n -2, fac);
    long long B = factorial(k-2, fac);
    long long C = factorial(m*n -2 - (k-2), fac);

    long long denominator = (B*C)%MOD;

    long long ncr = (numerator*binaryExponentiation(denominator, MOD-2))%MOD;
    
    long long x = (((((n*n)%MOD*m)%MOD*((m*m)%MOD-1))%MOD))%MOD;
    long long y = (((((m*m)%MOD*n)%MOD*((n*n)%MOD-1))%MOD))%MOD;

    return (((x+y)*ncr)%MOD * binaryExponentiation(6, MOD-2))%MOD;

}
    
};