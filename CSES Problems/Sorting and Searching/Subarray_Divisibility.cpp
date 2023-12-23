    #include <bits/stdc++.h>
    using namespace std;

    #define int long long 

    void solve(){
        int n;
        cin>>n;


        vector<int> a(n);
        vector<int> pref(n);
        map<int, int> mp;

        for(int i = 0; i<n; i++){
            cin>>a[i];
        }

        pref[0] = a[0]%n;

        if(pref[0] < 0){
            pref[0]+= n;
        }

        for(int i = 1; i<n; i++){
            pref[i] = (a[i] + pref[i-1])%n;
            if(pref[i] < 0){
            pref[i]+= n;
        }
        }

        // for(auto it: pref){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        int res = 0;

        mp[0] = 1;

        for(int i = 0; i<n; i++){
            int x = pref[i];

            if(mp.find(x) != mp.end()){
                res+= mp[x];
            }

            mp[x]++;
        }

        cout<<res<<endl;
    }

    signed main(){

        solve();
    }