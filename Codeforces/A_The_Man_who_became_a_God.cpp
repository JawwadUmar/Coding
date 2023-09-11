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

void solve(){
    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    vector<int> diff;
    for(int i = 0; i<n; i++){
        
        cin>>a[i];
        if(i==0){
            continue;
        }

        diff.push_back(abs(a[i] - a[i-1]));
    }

    if(n==1  || k ==n){
        cout<<0<<endl;
        return;
    }

    int sum = 0;
    sort(diff.begin(), diff.end());

    for(auto it: diff){
        sum+= it;
    }

    k = k-1;
    int N = diff.size();

    for(int i = diff.size()-1; i>= max(0* 1LL, N-k); i--){
        sum-= diff[i];
    }

    cout<<sum<<endl;
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