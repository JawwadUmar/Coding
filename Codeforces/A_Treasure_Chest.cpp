#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'


void solve(){

    int x, y, k;
    cin>>x>>y>>k;

    if(x*y >= 0){
        //in the same direction

        if(abs(x) < abs(y)){
            
            int diff = abs(y) - abs(x);
            diff-= k;

            if(diff<0){
                diff = 0;
            }

            cout<<abs(y) + diff<<endl;
        }

        else{
            cout<<abs(x)<<endl;
        }
    }

    else{
        
        int p1 = 2*abs(x) + abs(y);
        int p2 = 2*abs(y) + abs(x);

        cout<<min(p1, p2)<<endl;
    }
    
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}