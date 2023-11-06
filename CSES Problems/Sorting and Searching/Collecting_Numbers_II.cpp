#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n, q;
    cin>>n>>q;

    vector<int> a(n);

    vector<pair<int, int>> v;
    unordered_map<int, int> mp;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        v.push_back({a[i], i});
        mp[a[i]] = i;
    }

    sort(v.begin(), v.end());
    int cnt = 1;

    for(int i = 1; i<v.size(); i++){

        if(v[i].second < v[i-1].second){
            cnt++;
        }
    }

    // cout<<cnt<<endl;

    for(int i = 0; i<q; i++){
        int l, r;
        cin>>l>>r;

        l--;
        r--;
        set<pair<int, int>> st;

        if(a[l]-1 > 0){
            st.insert({a[l] -1, a[l]});
        }

        if(a[r]-1 > 0){
            st.insert({a[r]-1, a[r]});
        }

        if(a[l] +1 <=n){
            st.insert({a[l], a[l]+1});
        }

        if(a[r] +1 <= n){
            st.insert({a[r], a[r]+1});
        }

        // for(auto it: st){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        int initialScore = 0;

        for(auto it: st){
            int num1 = it.first;
            int num2 = it.second;

            int i1 = mp[num1];
            int i2 = mp[num2];


            if(i1> i2){
                initialScore--;
            }

            else{
                initialScore++;
            }
        }

        mp[a[l]] = r;
        mp[a[r]] = l;

        swap(a[l], a[r]);

        int finaScore = 0;

        for(auto it: st){
            int num1 = it.first;
            int num2 = it.second;

            int i1 = mp[num1];
            int i2 = mp[num2];


            if(i1> i2){
                finaScore--;
            }

            else{
                finaScore++;
            }
        }

        // cout<<initialScore<<" "<<finaScore<<endl;

        int diff = (finaScore - initialScore)/2;

        // cout<<diff<<endl;
        cnt-= diff;

        cout<<cnt<<endl;
        
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}