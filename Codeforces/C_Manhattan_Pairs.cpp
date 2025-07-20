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

static bool cmp1(vector<int> a, vector<int> b){
    
    return a[0] < b[0];
   
}

static bool cmp2(vector<int> a, vector<int> b){
    
    return a[1] < b[1];
   
}

vector<int> findIntersection(vector<int> a, vector<int> b){
    vector<int> res;

    set<int> st (a.begin(), a.end());

    for(int x: b){
        if(st.count(x)){
            res.push_back(x);
        }
    }

    return res;
}


void solve(){

    int n;
    cin>>n;

    vector<vector<int>> a(n);

    for(int i = 0; i<n; i++){
        int x, y;
        cin>>x>>y;

        a[i] = {x, y, i};
    }

    sort(a.begin(), a.end(), cmp1);
    vector<int> xl;
    vector<int> xr;

    for(int i =0; i<n/2; i++){
        xl.push_back(a[i].back());
        xr.push_back(a[n-i-1].back());
    }

    sort(a.begin(), a.end(), cmp2);
    vector<int> yl;
    vector<int> yr;

    for(int i =0; i<n/2; i++){
        yl.push_back(a[i].back());
        yr.push_back(a[n-i-1].back());
    }

    // xlyl and xryr
    // xlyr and xryl
    vector<int> xlyl = findIntersection(xl, yl);
    vector<int> xryr = findIntersection(xr, yr);

    for(int i =0; i<xlyl.size(); i++){
        cout<<xlyl[i]+1<<" "<<xryr[i]+1<<endl;
    }

    vector<int> xlyr = findIntersection(xl, yr);
    vector<int> xryl = findIntersection(xr, yl);

    for(int i =0; i<xlyr.size(); i++){
        cout<<xlyr[i]+1<<" "<<xryl[i]+1<<endl;
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