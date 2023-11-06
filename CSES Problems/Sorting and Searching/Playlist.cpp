#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

void solve(){

    int n;
    cin>>n;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    map<int, int> mp;

    int i = 0;
    int j = 0;
    int res = 1;

    while (j<n)
    {
        mp[a[j]]++;

        while (i<n && mp[a[j]] > 1)
        {
            mp[a[i]]--;
            i++;
        }

        res = max(res, j-i+1);
        j++;
    }
    
    cout<<res<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}