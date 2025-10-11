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

    int n,k;
    cin>>n>>k;

    if(k == n*n -1){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    vector<vector<char>> v(n, vector<char> (n, 'U'));

    // if(k == 0){
    //     //no escape possbile 
    //     for(int i = 0; i<n; i++){
    //         v[0][i] = 'D';
    //         v[n-1][i] = 'U';
    //     }

    //     for(int j = 1; j<n-1; j++){
    //         v[j][0] = 'R';
    //         v[j][n-1] = 'L';
    //     }
        
    //     print(v);
    //     return;
    // }

    

   

    if(k == n*n){
        print(v);
        return;
    }

    int r = (k-1)/n;
    int c = (k-1)%n;

    // cout<<r<<" "<<c<<endl;
    //except for the last row, sbme dd dd 

    for(int j = c+1; j<n; j++){
        v[r][j] = 'D';
    }

    for(int i = r+1; i<n-1; i++){
        for(int j = 0; j<n; j++){
            v[i][j] = 'D';
        }
    }

    v[n-1][n-1] = 'L';
    
    if(r == n-1){
        for(int j = c+1; j<n-1; j++){
            v[r][j] = 'R';
        }
    }

    else{

        v[n-1][0] = 'R';
        for(int j = 1; j<n-1; j++){
            v[n-1][j] = 'R';
        }

    }

    print(v);




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