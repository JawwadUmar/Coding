#include <bits/stdc++.h>
using namespace std;


int sumPrime(int rangeLeft, int rangeRight){
    int n = max(abs(rangeLeft), abs(rangeRight));
    vector<int> sieve(n+1, 1);
    sieve[0] = sieve[1] = 0;

    for(int i = 2; i*i<=n; i++){
        if(sieve[i] == 1){
            for(int j = i*i; j<=n; j+=i){
                sieve[j] = 0;
            }
        }
    }
    long long sum = 0;
    for(int i = rangeLeft; i<=rangeRight; i++){
        int x = abs(i);
        if(sieve[x] == 1){
            sum+=i;
        }
    }

    return sum;
}

int main(){
    int rangeLeft;
    cin>>rangeLeft;

    int rangeRight;
    cin>>rangeRight;
    
    int result = sumPrime(rangeLeft, rangeRight);   

    cout<<result;

    return 0;
}