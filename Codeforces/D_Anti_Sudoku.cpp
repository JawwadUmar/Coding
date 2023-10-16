#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;

void solve(){

    vector<string> v;

    vector<char> zz;
    vector<char> tt;
    vector<char> ss;

    for(int i= 0; i<9; i++){
        string s;
        cin>>s;
        v.push_back(s);
    }

    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){

            if(i==j){
                if(i<=2){
                    zz.push_back(v[i][j]);
                }

                else if(i<=5){
                    tt.push_back(v[i][j]);
                }

                else{
                    ss.push_back(v[i][j]);
                }
            }
            // cout<<v[i][j];
        }

        // cout<<endl;
    }


    // for(auto it:tt){
    //     cout<<it<<" ";
    // }

    // cout<<endl;

    //tt->zz
    //zz->ss ///ok
    //ss->tt ///ok

    int cnt =0;
    for(int i = 0; i<=2; i++){
        v[i][i] = ss[cnt];
        cnt++;
    }

    cnt =0;
    for(int i = 6; i<=8; i++){
        v[i][i] = tt[cnt];
        cnt++;
    }

    cnt =0;
    for(int i = 3; i<=5; i++){
        v[i][i] = zz[cnt];
        cnt++;
    }


    for(int i = 0; i<9; i++){
        cout<<v[i]<<endl;
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