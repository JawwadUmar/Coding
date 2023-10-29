#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

void solve(){

    int n, x;
    cin>>n>>x;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    int x1, y1;
    bool flag = false;

    multiset<int> m (a.begin(), a.end());

    for(int i = 0; i<n; i++){
        auto it1 = m.find(a[i]);
        m.erase(it1);

        auto it2 = m.find(x - a[i]);

        if(it2 != m.end()){
            flag = true;
            x1 = a[i];
            y1 = *it2;
            break;
        }

        m.insert(a[i]);
    }

    if(flag == false){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    int idx1 = -1;
    int idx2 = -1;

    for(int i = 0; i<n; i++){
        if(a[i] == x1 && idx1 ==-1){
            idx1 = i+1;
        }

        else if(a[i] == y1 && idx2 ==-1){
            idx2 = i+1;
        }
    }

    cout<<idx1<<" "<<idx2<<endl;



}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}