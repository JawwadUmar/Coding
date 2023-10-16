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

//ctrl shift B for output

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}


void solve(){

    int n, mxWt;
    cin>>n>>mxWt;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());

    int i = 0;
    int j = n-1;
    int cnt = 0;

    while (j>i)
    {
         int combinedWt = a[i] + a[j];

         if(combinedWt<=mxWt){
            i++;
            j--;
            cnt++;
         }

         else{
            j--;
            cnt++;
         }
    }

    if(i == j){
        cnt++;
    }
    
    cout<<cnt<<endl;
    
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}