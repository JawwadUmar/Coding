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
    int n;
    cin>>n;

    string s;
    cin>>s;

    if(n<4){
        cout<<"NO"<<endl;
        return;
    }

    if(s[0] != 'm' && s[0] != 'M'){
        cout<<"NO"<<endl;
        return;
    }

    int i = 1;

    while (i< n && (s[i] == 'm' || s[i] == 'M'))
    {
        i++;
    }

    if(i ==n || (s[i] != 'e' && s[i] != 'E')){
        cout<<"NO"<<endl;
        return;
    }

    while (i< n && (s[i] == 'e' || s[i] == 'E'))
    {
        i++;
    }

    if(i ==n || (s[i] != 'o' && s[i] != 'O')){
        cout<<"NO"<<endl;
        return;
    }

    while (i< n && (s[i] == 'o' || s[i] == 'O'))
    {
        i++;
    }

    if(i ==n || (s[i] != 'w' && s[i] != 'W')){
        cout<<"NO"<<endl;
        return;
    }

     while (i< n && (s[i] == 'w' || s[i] == 'W'))
    {
        i++;
    }

    if(i == n){
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
    
    int t;
    // t=1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}