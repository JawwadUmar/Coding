#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long




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


void solve(){

    int n, a, b;
    cin>>n>>a>>b;

    string s;
    cin>>s;

    string temp = s;

    for(int i = 0; i<100; i++){
        s = s + temp;
    }
    
    int x, y;
    x = y = 0;

    if(x == a && y == b){
        cout<<"YES"<<endl;
        return;
    }

    for(int i = 0; i<s.size(); i++){
        
        if(s[i] == 'N'){
            y+=1;
        }

        else if(s[i] == 'E'){
            x+=1;
        }

        else if(s[i] == 'W'){
            x-=1;
        }

        else if(s[i] == 'S'){
            y-=1;
        }

        if(x == a && y == b){
        cout<<"YES"<<endl;
        return;
    }
        
    }

    cout<<"NO"<<endl;
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