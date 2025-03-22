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


bool allElementsSame(string &s){
    char ch  = s[0];

    for(int i = 1; i<s.size(); i++){
        if(s[i] != ch){
            return false;
        }
    }

    return true;
}


void solve(){

    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;

    string rev = s;
    reverse(rev.begin(), rev.end());

    if(rev > s){
        cout<<"YES"<<endl;
        return;
    }

    else if(k ==0){
        cout<<"NO"<<endl;
    }

    else if(allElementsSame(s)){
        cout<<"NO"<<endl;
    }

    else{
        cout<<"YES"<<endl;
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