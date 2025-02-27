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
    int m;
    cin>>m;

    vector<int> a(n);
    for(int i =0; i<n; i++){
        cin>>a[i];
    }

    vector<int> b(m);

    for(int i = 0; i<m; i++){
        cin>>b[i];
    }

    int x = b[0];
    
    if(a[0] > x-a[0]){
        a[0] = x-a[0]; //Can also make sth big
    }

    for(int i =1; i<n; i++){

        if(a[i] >= a[i-1]){

            if(a[i] > x - a[i]){
                if(x-a[i] >= a[i-1]){
                    a[i] = x - a[i];
                }
            }
        }

        else{

            //problematic
            //a[i] chhota h 
            if(a[i] < x-a[i]){
                if(x-a[i] >= a[i-1]){
                    a[i] = x-a[i];
                }
            }
            
        }
    }


    for(int i = 1; i<n; i++){
        if(a[i] < a[i-1]){
            cout<<"NO"<<endl;
            return;
        }
    }

     cout<<"YES"<<endl;

    
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