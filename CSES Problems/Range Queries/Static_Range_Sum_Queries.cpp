#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){

    int n, q;
    cin>>n>>q;

    vector<int> a(n+1);

    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }

    vector<int> pref(n+1, 0);

    for(int i = 1; i<=n; i++){
        pref[i] = a[i] + pref[i-1];
    }

    for(int i = 0; i<q; i++){
        int l, r;
        cin>>l>>r;

        cout<<pref[r] - pref[l-1]<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}