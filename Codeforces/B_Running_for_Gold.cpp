#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

bool better(int curr, int prev, vector<vector<int>>& rank){

    int cnt = 0;
    for(int i = 0; i<5; i++){
        
        if(rank[curr][i] < rank[prev][i]){
            cnt++;
        }

        else{
            cnt--;
        }
    }

    return cnt>0;
}


void solve(){

    int n;
    cin>>n;

    vector<vector<int>> rank (n, vector<int> (5));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<5; j++){

            cin>>rank[i][j];
        }
    }

    int winn = 0;

    for(int i = 1; i<n; i++){

        if(better(i, winn, rank)){
            winn = i;
        }
    }


    for(int i = 0; i<n; i++){

        if(i==winn){
            continue;
        }

        if(better(i, winn, rank)){
            cout<<-1<<endl;
            return;
        }
    }

    cout<<winn+1<<endl;


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