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


bool water(int mid, vector<int> &a, int x){
    int res = 0;
    for(int i = 0; i<a.size(); i++){
        if(mid>= a[i]){
            res+= mid-a[i];

            if(res > x){
                return false;
            }
        }
    }

    return true;
}

void solve(){
    int n, x;
    cin>>n>>x;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    // cout<<water(5, a)<<endl;

    int low = 1;
    int high = 1e18;

    int res = 1;

    while (high>=low)
    {
        int mid = high - (high - low)/2;

        if(water(mid, a, x)){
            res = mid;
            low = mid+1;
        }

        else{
            high = mid-1;
        }
    }

    cout<<res<<endl;

    

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