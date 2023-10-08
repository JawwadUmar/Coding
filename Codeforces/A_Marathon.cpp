#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    vector<pair<int, string>> v;

    v.push_back({a, "a"});
    v.push_back({b, "b"});
    v.push_back({c, "c"});
    v.push_back({d, "d"});

    sort(v.begin(), v.end());

    auto it = lower_bound(v.begin(), v.end(), make_pair(a, string ("a")));

    int idx = it - v.begin();

    idx = 4 - idx;

    cout<<idx-1<<endl;
    

}

int main(){
    int t;
    cin>>t;

    while (t--)
    {
        solve();
    }

    return 0;
    
}