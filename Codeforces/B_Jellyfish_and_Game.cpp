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


void solve(){

    int n, m, k;
    cin>>n>>m>>k;

    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    for(int j = 0; j<m; j++){
        cin>>b[j];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(k%2){
        k = 1;
    }

    else{
        k = 2;
    }

    int a_max = a.back();
    int a_min = a.front();

    int b_max = b.back();
    int b_min = b.front();

    if(k == 1){

        if(b_max > a_min){
            swap(a[0], b[m-1]);
        }
    }

    else if(k ==2){
        if(b_max > a_min){
            swap(a[0], b[m-1]);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if(a.back() > b.front()){
            swap(a[n-1], b[0]);
        }
    }

    int sum = 0;

    for(auto it: a){
        sum+= it;
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