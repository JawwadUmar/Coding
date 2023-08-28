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
    int n;
    cin>>n;
    int q;
    cin>>q;

    vector<vector<int>> v (4, vector<int> (n+2, 0));

    int bad = 0;

    while (q--)
    {
        int r, c;
        cin>>r>>c;
        

        v[r][c] = 1 - v[r][c];
            
            for(int i = r-1; i<=r+1; i++){
                for(int j = c-1; j<=c+1; j++){
                    if(i<1 || i>2 || i ==r){
                        continue;
                    }

                    if(v[i][j]){
                        if(v[r][c]){
                             bad++;
                        }

                        else{
                            bad--;
                        }
                    }
                }
            }

            if(bad>=1){
                cout<<"No"<<endl;
            }

            else{
                cout<<"Yes"<<endl;
            }
        }

}
    

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    t=1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}