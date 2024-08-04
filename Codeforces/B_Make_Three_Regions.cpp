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

    int m;
    cin>>m;
    vector<string> v;

    for(int i = 0; i<2; i++){
        string s;
        cin>>s;
        v.push_back(s);
    }

    int ans = 0;
    //check for placing x in the first row
    
    for(int j = 0; j<m; j++){
        if(j == 0 || j == m-1){
            continue;
        }

        if(v[0][j] == '.'){
            if(v[1][j+1] == 'x' && v[1][j-1] == 'x'){
                if(v[0][j+1] == '.' && v[0][j-1] == '.' && v[1][j] == '.'){
                    ans++;
                }
            }
        }

        if(v[1][j] == '.'){
            if(v[0][j+1] == 'x' && v[0][j-1] == 'x'){
                if(v[1][j+1] == '.' && v[1][j-1] == '.' && v[0][j] == '.'){
                    ans++;
                }
            }
        }
        
    }

    cout<<ans<<endl;
    
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