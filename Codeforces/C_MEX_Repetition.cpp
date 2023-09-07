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

void rotate(int n , int k, vector<int> &a){

    k = k%n;
    reverse(a.begin(), a.begin()+ n - k);
    reverse(a.begin()+ n-k, a.end()); 

    reverse(a.begin(), a.end());
}

void solve(){
    int n, k;

    cin>>n>>k;

    set<int> st;

    for(int i = 0; i<=n; i++){
        st.insert(i);
    }

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
        st.erase(a[i]);
    }

    //one operation
    for(int i = 0; i<n; i++){
        int temp = a[i];
        a[i] = *st.begin();
        st.erase(st.begin());

        if(temp<= n){
            st.insert(temp);
        }
    }

    k = k-1;

    // for(auto it: a){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    vector<int> b = a;

    b.push_back(*st.begin());

    // cout<<"k "<<k<<endl;

    rotate(b.size(), k, b);

    b.pop_back();

    for(auto it: b){
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