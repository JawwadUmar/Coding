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


vector<vector<int>> multiplyMat( vector<vector<int>> A, vector<vector<int>> B){

    vector<vector<int>> res (A.size(), vector<int> (B[0].size(), 0));

    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j<B.size(); j++){
            int x = 0;
            for(int k = 0; k<A[0].size(); k++){
                x = (x+ (A[i][k] * B[k][j])%MOD)%MOD;
                x = x%MOD;
            }

            res[i][j] = x%MOD;
            }
        }

    return res;
}


vector<vector<int>> binExp( vector<vector<int>> mat, int p){
    if(p == 0){
        return {{1, 0}, {0,1}};
    }

    vector<vector<int>> res = binExp(mat, p/2);
    res = multiplyMat(res, res);
    if(p%2 == 1){
        res = multiplyMat(mat, res);
    }

    return res;
}


void solve(){

    int n;
    cin>>n;

    if(n==0){
        cout<<n<<endl;
        return;
    }
    
    vector<vector<int>> mat {{1, 1}, {1, 0}};
    vector<vector<int>> base {{1} , {0}};
    
    vector<vector<int>> res = binExp(mat, n-1);
    
    res = multiplyMat(res, base);


    cout<<res[0][0]<<endl;


}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}