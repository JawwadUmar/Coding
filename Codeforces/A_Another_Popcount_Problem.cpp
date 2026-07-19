#include <bits/stdc++.h>
using namespace std;

#define int long long 


int nearestPow2(int x){
    int cnt = 0;
    while (x)
    {
        cnt++;
        x = x/2;
    }

    return 1<<(cnt-1);
    
}

bool allbitset(int x){
    bool falg = true;

    while (x)
    {
        if(x%2 == 0){
            return false;
        }
         x = x/2;
    }

    return true;
    
}

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}

void solve(){
    int n, k;
    cin>>n>>k;

    if(k>=n){
        cout<<n<<endl;
        return;
    }

    int res = 0;

    while (k>0)
    {
        int sum = n;
        int perbox = sum/k;

        if(allbitset(perbox)){
            res+= numberOfSetBits(perbox);
        }
        else{
            int nearestpowerof2 = nearestPow2(perbox);
            perbox = nearestpowerof2-1;
            res+= numberOfSetBits(perbox);
        }

        n-= perbox;
        k--;
    }
    
    cout<<res<<endl;
}

signed main(){
    int t;
    cin>>t;

    while (t--)
    {
        solve();
    }
    
}