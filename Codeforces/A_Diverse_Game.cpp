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

    int n, m;
    cin>>n>>m;


    vector<vector<int>> mat(n, vector<int> (m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>mat[i][j];
        }
    }

    if(m == n && n==1){
        cout<<-1<<endl;
        return;
    }

    if(m==1){
        int i = 0;
        int j = n-1;

        while (j>i)
        {
            swap(mat[i][0], mat[j][0]);
            j--;
            i++;
        }

        if(n%2){
            swap(mat[n/2][0], mat[n/2 +1][0]);
        }

        for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return;
        
    }

    for(int i = 0; i<n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }


    if(m%2){
        for(int i = 0; i<n; i++){
            swap(mat[i][m/2], mat[i][m/2+1]);
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
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