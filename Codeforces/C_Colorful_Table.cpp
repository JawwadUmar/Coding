#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

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

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
 

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    // set<int> st(a.begin(), a.end());
    vector<int> temp(a.begin(), a.end());

    sort(temp.begin(), temp.end());

    vector<int> left (k+1, n-1);
    vector<int> right (k+1, 0);

    for(int i = 0; i<n; i++){

        left[a[i]] = min(left[a[i]], i);
        right[a[i]] = max(right[a[i]], i);
    }

    for(int i = k-1; i>=0; i--){
        right[i] = max(right[i+1], right[i]);
        left[i] = min(left[i+1], left[i]);
    }



    vector<int> res;

    for(int i = 1; i<=k; i++){
        auto it = lower_bound(temp.begin(), temp.end(), i);

        if(it == temp.end() || *it != i){
            res.push_back(0);
            continue;
        }

        int pos = it - temp.begin();
        int bigger_than = temp.size() - pos;

        int curr = max(bigger_than*2, (right[i]-left[i] + 1)*2);
        res.push_back(curr);
        // res.push_back((right[i]-left[i] + 1)*2);
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
    
    int t = 1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}