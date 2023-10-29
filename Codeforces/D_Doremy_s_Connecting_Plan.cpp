#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'


void solve(){

    int n, c;
    cin>>n>>c;

    vector<int> a(n+1);
    multiset<int> st;

    map<int, set<int>> mp;

    for(int i = 1; i<=n; i++){
        cin>>a[i];

        if(i==1){
            continue;
        }
        st.insert(a[i]);
        mp[a[i]].insert(i);
    }

    int currsum = a[1];

    set<int> vis;

    for(int j = 2; j<=n; j++){
        vis.insert(j);
    }

    while (!vis.empty())
    {
        int del = -1;

        for(auto it: vis){
            
            int x = it*c - currsum;

            int num = a[it];

            if(num>=x){
                currsum+= num;
                del = it;
                break;
            }
        }

        if(del == -1){
            cout<<"No"<<endl;
            return;
        }

        vis.erase(del);
    }

    // cout<<currsum<<endl;
    cout<<"Yes"<<endl;
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