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
    int n, m;
    cin>>n>>m;

    vector<int> initial_colors(n);
    vector<int> final_colors(n);
    map<int,set<int>> mpfence;

    

    for(int i = 0; i<n; i++){
        cin>>initial_colors[i];
    }

    for(int i = 0; i<n; i++){
        cin>>final_colors[i];
        if(final_colors[i] != initial_colors[i]){
            mpfence[final_colors[i]].insert(i);
        }
    }

    vector<int> painter_colors(m);

    int lastColor = -1;

    map<int, int> freq;
    for(int i = 0; i<m; i++){
        cin>>painter_colors[i];
        freq[painter_colors[i]]++;

        if(i == m-1){
            lastColor = painter_colors[i];
        }
    }

    int idx = -1; //index at which final color is last color

    for(int i = 0; i<n; i++){
        if(final_colors[i] == lastColor && initial_colors[i] != final_colors[i]){
            idx = i;
        }
    }

    // cout<<idx<<endl;

    if(idx == -1){
        for(int i = 0; i<n; i++){
        if(final_colors[i] == lastColor){
            idx = i;
        }
    }

    if(idx == -1){
        cout<<"NO"<<endl;
        return;
    }
    }

    map<int, int> mpreq;

    for(int i = 0; i<n; i++){
        if(initial_colors[i] != final_colors[i]){
            mpreq[final_colors[i]]++;

            if(mpreq[final_colors[i]] > freq[final_colors[i]]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;
    vector<int> res(m, -1);

    for(int i = 0; i<m; i++){
        int color = painter_colors[i];

        if(mpreq[color]){
            mpreq[color]--;

            res[i] = *mpfence[color].begin() +1;
            mpfence[color].erase(mpfence[color].begin());
        }

        else{
            res[i] = idx+1;
        }
    }

    for(auto it: res){
        cout<<it<<" ";
    }
    cout<<endl;

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