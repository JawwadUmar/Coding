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


string add(string &s){
    return s+s;
}

bool findSub(string s1, string s2){

    if(s2.find(s1) != string::npos){
        return true;
    }

    return false;
}


void solve(){

    int n, m;
    cin>>n>>m;

    string s1, s2;
    cin>>s1>>s2;

    int cnt = 0;

    while (s2.size() >= s1.size())
    {
        if(findSub(s2, s1)){
            cout<<cnt<<endl;
            return;
        }

        s1 = add(s1);
        cnt++;
    }

    if(findSub(s2, s1)){
    cout<<cnt<<endl;
    return;
 }

    s1 = add(s1);
    cnt++;
    if(findSub(s2, s1)){
    cout<<cnt<<endl;
    return;
 }

    

    

    cout<<-1<<endl;
    



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