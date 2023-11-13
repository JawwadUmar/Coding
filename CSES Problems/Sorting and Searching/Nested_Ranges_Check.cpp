#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


static bool cmp(pair<int, int> p1, pair<int, int> p2){

    if(p1.first < p2.first){
        return true;
    }

    if(p1.first == p2.first){
        return p1.second > p2.second;
    }

    return false;
}

void solve(){
    int n;
    cin>>n;

    vector<pair<int, int>> v;
    map<pair<int, int>, int> mp;

    for(int i = 0; i<n; i++){
        int a, b;
        cin>>a>>b;
        v.push_back({a, b});
        mp[make_pair(a, b)] = i;
    }

    sort(v.begin(), v.end(), cmp);

    int mxR = v[0].second;
    vector<int> contained(n, 0);

    for(int i = 1; i<n; i++){

        if(v[i].second <= mxR){
            int idx = mp[v[i]];
            contained[idx] = 1;
        }

        else{
            mxR = v[i].second;
        }
    }

    vector<int> contains(n, 0);
    int mnR = INT_MAX;

    for(int i = n-1; i>=0; i--){

        if(v[i].second >= mnR){
            int idx = mp[v[i]];
            contains[idx] = 1;
        }

        else{
            mnR = v[i].second;
        }
    }

    for(auto it: contains){
        cout<<it<<" ";
    }

    cout<<endl;

    for(auto it: contained){
        cout<<it<<" ";
    }

    cout<<endl;
}

signed main(){

    solve();
}