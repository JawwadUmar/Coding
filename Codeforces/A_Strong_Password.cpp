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

    string s;
    cin>>s;

    string res = "";
    bool flag = true;

    for(int i = 0; i<s.size()-1; i++){
        if(s[i] == s[i+1] && flag == true){
            res+= s[i];
            if(s[i] == 'a'){
                res+= s[i] + 1;
            }

            else if(s[i] == 'z'){
                res+= s[i]-1;
            }

            else{
                res+= s[i]+1;
            }
            flag = false;
        }

        else{
            res+= s[i];
        }
    }

    res+= s.back();

    if(flag == true){
        if(res.back() == 'a'){
            res+='b';
        }

        else{
            res+= res.back()-1;
        }
    }

    cout<<res<<endl;
    
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