#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
unordered_set<int> st;

bool flag(int n){

    if((long long) ((1e18)/n) > n){
        return false;
    }
 
    int D = 1 + 4*(n-1);
 
    int d = sqrtl(D);
    
    if(d*d !=D){
        return false;
    }
 
    if((d-1)%2 != 0){
        return false;
    }
 
    int r = (d-1)/2;
 
    if(r<=1){
        return false;
    }
 
    return true;
}

void solve(){
    int n;
    cin>>n;

    if(n<7){
        cout<<"NO"<<endl;
        return;
    }

    if(flag(n)){
        cout<<"YES"<<endl;
        return;
    }

    if(st.count(n)){
        cout<<"YES"<<endl;
    }

    else{
         cout<<"NO"<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    for(int a = 2; a<=10000; a++){

        int r = a;
        int val = 1;

        int cnt = 63;

        for(int j = 1; j<=cnt; j++){
            val+= r;

            if(val> 1e18){
                break;
            }
            if(j>=2){
                st.insert(val);
            }
            
            r = r*a;

            if(r > (long long)(1e18)/a){
                break;
            }

        }
    }

   
    
    int t;
    // t=1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}