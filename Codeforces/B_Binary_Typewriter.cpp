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


int calculateCost(string &s){
    int n = s.size();
    int handson = 0;
    int res = 0;
    for(int i = 0; i<n; i++){
        int x = s[i] - '0';

        if(x != handson){
            handson = 1- handson;
            res++;
        }
    }

    
    return res+n;
}

void solve(){

    int n;
    cin>>n;
    string s;
    cin>>s;

    int l = 0;
    while (l<n && s[l] =='0')
    {
        l++;
    }

    int r = n-1;
    for(int idx = l+1; idx <n-1; idx++){

        if(s[idx] == '0' && s[idx+1] == '1'){
            r = idx;
            break;
        }
    }

    reverse(s.begin()+l, s.begin()+r+1);
    cout<<calculateCost(s)<<endl;
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


// 1101010010011011100