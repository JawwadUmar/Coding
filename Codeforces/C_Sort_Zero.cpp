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

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}

void print(vector<int>&a){
    for(int i = 0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


void solve(){

    int n;
    cin>>n;

    map<int, set<int>> mp;
    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
        mp[a[i]].insert(i);
    }

    set<int> st;
    st.insert(a[0]);
    int res = 0;
    for(int i = 1; i<n; i++){
        if(a[i] < a[i-1]){

            // cout<<i<<endl;
            res+= st.size();

            for(auto elements: st){
                
                set<int> temp = mp[elements];


                for(auto it: temp){
                    a[it] = 0;
                }
            }
            st.clear();
        }

        // print(a);

        if(a[i] != 0){
         st.insert(a[i]);
        }
    }

    cout<<res<<endl;
    
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