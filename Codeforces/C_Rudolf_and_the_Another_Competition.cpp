#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
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

void solve(){
    int n, m, h;
    cin>>n>>m>>h;

    vector<vector<int>> mat(n, vector<int> (m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>mat[i][j];
        }
    }

    vector<int> score(n, 0);
    vector<int> penalty(n, 0);

    

    for(int i =0; i<n; i++){
        sort(mat[i].begin(), mat[i].end());

        int temp = h;
        int p = 0;
        for(int j = 0; j<m; j++){
            if(mat[i][j] <= temp){
                temp-= mat[i][j];
                p+= mat[i][j];
                penalty[i]+= p;
                score[i]+= 1;
            }
        }
    }

    // for(int i = 0; i<n; i++){
    //     for(auto it: mat[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<endl;

    // for(int i =0 ;i<n; i++){
    //     cout<<score[i]<<" ";
    // }

    // cout<<endl;

    // for(int i =0 ;i<n; i++){
    //     cout<<penalty[i]<<" ";
    // }

    // cout<<endl;

    vector< pair< pair<int, int>, int>> v;

    for(int i = 0; i<n; i++){
        v.push_back({{score[i], -penalty[i]}, n-i});
    }

    sort(v.begin(), v.end());

    int rank = 1;
    for(int i = n-1; i>=0; i--){
        if(v[i].second == n){
            break;
        }

        else{
            rank++;
        }
    }

    cout<<rank<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    // t=1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}