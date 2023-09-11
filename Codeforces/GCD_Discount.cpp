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

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}

int HCF(vector<int> &a){
    int st  = a[0];

    for(int i= 1; i<a.size(); i++){
        st = __gcd(st, a[i]);
    }

    return st;
}


void solve(){
    
    int n;
    cin>>n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i = 0; i<n; i++){
        cin>>b[i];
    }

    vector<int> temp1 = a;
    vector<int> temp2 = a;

    for(int i = 1; i<n; i++){
        int x = __gcd(a[i], a[i-1]);
        int y = __gcd(a[i], b[i-1]);
        int z = __gcd(a[i-1], b[i]);

        if(x<y || x<z){
            if(x<y){
                temp1[i-1] = y;
            }

            if(x<z){
                temp2[i] = z;
            }

            break;
        }
    }

    int ans1 = HCF(a);
    int ans2 = HCF(temp1);
    int ans3 = HCF(temp2);

    cout<<max({ans1, ans2, ans3})<<endl;
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