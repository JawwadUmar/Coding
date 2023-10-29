#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

int f(int mid, vector<int> &a){
    int res = 0;

    for(auto it: a){
        res+= abs(it-mid);
    }

    return res;
}

void solve(){

    int n;
    cin>>n;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());

    int mid1 = a[n/2];

    if(n%2){
        cout<<f(mid1, a)<<endl;
    }

    else{
        int mid = a[n/2] + a[n/2 -1];
        mid = mid/2;

        cout<<f(mid, a)<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    solve();
}