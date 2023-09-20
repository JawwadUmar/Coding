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
    if(n==1){
        return false;
    }

    if(n==2){
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
    int n;
    cin>>n;

    if(n ==1){
        cout<<1<<endl;
        return;
    }

    if(n==2){
        cout<<"2 1"<<endl;
        return;
    }

    if(n==3){
        cout<<"3 1 2"<<endl;
        return;
    }

    vector<int> res(n);

    if(isPrime(n)){
        res[0] = n;
        res[1] = 2;
        res[n/2] = 1;
        res[n-1] = 3;
        int idx = 4;
        for(int i = 2; i<n/2; i++){
            res[i] = idx;
            idx++;
        }

        for(int i = n/2+1; i<=n-2; i++){
            res[i] = idx;
            idx++;
        }
    }

    else{
        res[0] = 2;
        res[n/2] = 1;
        res[n-1] = 3;

        int idx = 4;
        for(int i = 1; i<n/2; i++){
            res[i] = idx;
            idx++;
        }

        for(int i = n/2+1; i<=n-2; i++){
            res[i] = idx;
            idx++;
        }
    } 

    for(auto it:res){
        cout<<it<<" ";
    }

    cout<<endl;
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