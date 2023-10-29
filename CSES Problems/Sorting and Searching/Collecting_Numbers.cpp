#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;

    vector<pair<int, int>> v;

    for(int i = 0; i<n; i++){
        int x;
        cin>>x;

        v.push_back({x, i+1});
    }

    sort(v.begin(), v.end());

    int cnt =1;

    int i = 1;
    int lastidx = v[0].second;

    while (i<n)
    {
        if(v[i].second < lastidx){
            cnt++;
        } 

        lastidx = v[i].second;
        i++;
    }

    cout<<cnt<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

}