#include <bits/stdc++.h>
using namespace std;
#define int long long

static bool cmp(pair<int, int> a, pair<int, int> b){

    return a.second < b.second;
}

void solve(){

    int n;
    cin>>n;

    vector<pair<int, int>> v;

    for(int i = 0; i<n; i++){
        int a, b;
        cin>>a>>b;

        v.push_back({b, a});
    }

    sort(v.begin(), v.end());

    int cnt = 1;
    int i = 1;

    int last_end = v[i-1].first;

    while (i<n)
    {
        int curr_st = v[i].second;
        
        if(curr_st>=last_end){
            last_end = v[i].first;
            cnt++;
        }

        i++;
    }

    cout<<cnt<<endl;
    

}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    solve();
}
