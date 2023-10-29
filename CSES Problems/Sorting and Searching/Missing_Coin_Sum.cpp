#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

//oooooooh algorithm 

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());

    int res = 1;
    int i = 0;

    while (i<n && a[i] <= res)
    {
        res+= a[i];
        i++;
    }

    cout<<res<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}