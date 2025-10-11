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


void print(vector<vector<char>> &v){

    int n = v.size();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<v[i][j];
        }

        cout<<endl;
    }
}

void solve(){

    int x, y, z;
    cin>>x>>y>>z;

    vector<int> temp = {x, y, z};
    sort(temp.begin(), temp.end());

    int a = (temp[0]&temp[1]);
    int b = (temp[1]&temp[2]);
    int c = (temp[2]&temp[0]);

    if(a==b && b == c){
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
    
    int t = 1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}