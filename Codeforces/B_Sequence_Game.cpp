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
    int n;
    cin>>n;

    vector<int> b(n);
    vector<int> a;

    for(int i=0; i<n; i++){
        cin>>b[i];
    }

    a.push_back(b[0]);
    int j = 1;

    while(j<n){
        if(b[j] >= a.back()){
            a.push_back(b[j]);
            j++;
        }

        else{
            a.push_back(1);
        }
    }

    cout<<a.size()<<endl;

    for(auto it: a){
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