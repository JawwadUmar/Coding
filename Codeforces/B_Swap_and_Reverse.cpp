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

void solve(){
    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;

    if(k%2 ==0){
        sort(s.begin(), s.end());
        cout<<s<<endl;
        return;
    }

    string temp1;
    string temp2;

    for(int i = 0; i<n; i+=2){
        temp1.push_back(s[i]);
    }

    sort(temp1.begin(), temp1.end());

    for(int i = 1; i<n; i+=2){
        temp2.push_back(s[i]);
    }

    sort(temp2.begin(), temp2.end());

    int t1 = 0;
    int t2 = 0;

    for(int i=0; i<n; i++){
        if(i%2 ==0){
            s[i] = temp1[t1];
            t1++;
        }

        else{
            s[i] = temp2[t2];
            t2++;
        }
    }

    cout<<s<<endl;
    
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