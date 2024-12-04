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

    int n;
    cin>>n;

    string s;
    cin>>s;

    map<char, int> mp;

    for(int i = 0; i<n; i++){
        mp[s[i]]++;
    }

    int most = 0;
    char mostChar;

    int least = 1e9;
    char leastChar;

    for(auto it: mp){

        if(it.second >= most){
            most = it.second;
            mostChar = it.first;
        }

        if(it.second < least){
            least = it.second;
            leastChar = it.first;
        }
    }

    if(leastChar == mostChar){
        s[0] = s[n-1];
        cout<<s<<endl;
        return;
    }

    for(auto &it: s){
        if(it == leastChar){
            it = mostChar;
            break;
        }
    }

    cout<<s<<endl;
    
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