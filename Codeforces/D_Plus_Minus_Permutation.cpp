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
    // int n, x, y;
    // cin>>n>>x>>y;

    // int totalX = n/x;

    // int totalY = n/y;

    // int c = (x*y)/(__gcd(x,y));

    // totalX-=c;
    // totalY-=c;

    // int res1 = (((2*n + 1 -totalX))*(totalX))/2;

    // int res2 = (totalY*(totalY+1))/2;

    // int res = -(totalY*(totalY+1))/2;
    // res+= ((totalX*(totalX+1))/2) + ((n-totalX)*totalX);
    // cout<<res<<endl;
    


    int n,x,y;
    cin>>n>>x>>y;
    int a = n / x;
    int b = n / y;
    int c = n / ((x*y)/__gcd(x,y));
    a = a - c;
    b = b - c;
    
    // int res2 = (totalY*(totalY+1))/2;
    int res = -(b * (b + 1)) / 2;
    res += ((a * (a + 1)) / 2) + ((n - a) * a);
    cout << res << endl;
  
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