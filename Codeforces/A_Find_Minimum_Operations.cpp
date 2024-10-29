#include <bits/stdc++.h>
using namespace std;

#define int long long


int binaryExponentiation(int x, int p){
    int res = 1;
    while(p){
        if(p%2){
            res = (res * x);
        }

        x = (x*x);
        p = p/2;
    }
    
    return res;
}

int f(int n, int k){
    //logk N
    int res = 0;

    for(int i = 0; i<32; i++){
        if(binaryExponentiation(k, i) <= n){
            res = i;
        }
        else{
            break;
        }
    }

    return res;
}

void solve(){
    int n, k;
    cin>>n>>k;

    if(k>n){
        cout<<n<<endl;
        return;
    }

    else if(k == n){
        cout<<1<<endl;
        return;
    }

    int cnt = 0;

    while (n > k)
    {
        int x = f(n, k);
        int y = (int)(binaryExponentiation(k, x));
        int z = n/y;
        
        n = n-z*y;
        cnt+=z;
    }

    // cout<<n<<endl;

    if(k == n){
        cout<<cnt + 1<<endl;
        return;
    }
    
    cout<<cnt +n <<endl;
}

signed main(){
    
    int t;
    cin>>t;

    while (t--)
    {
        solve();
    }
}