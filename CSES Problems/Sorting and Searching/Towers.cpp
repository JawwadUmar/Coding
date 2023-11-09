#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<int> a(n);

    multiset<int> m;

    for(int i = 0; i<n; i++){
        cin>>a[i];

        if(m.empty()){
            m.insert(a[i]);
            continue;
        }

        auto it = m.upper_bound(a[i]);

        if(it== m.end()){
            m.insert(a[i]);
        }

        else{
            m.erase(it);
            m.insert(a[i]);
        }

    }

    cout<<m.size()<<endl;


}