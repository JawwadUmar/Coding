    #include <bits/stdc++.h>
    using namespace std;

    #define int long long 

    void solve(){
        int n, target;
        cin>>n>>target;


        vector<int> a(n);
        vector<int> pref(n);
        map<int, int> mp;

        for(int i = 0; i<n; i++){
            cin>>a[i];

            if(i ==0){
                pref[i] = a[i];
                continue;
            }

            pref[i] = pref[i-1] + a[i];
        }

        int res = 0;
        mp[0]++;
        
        for(int i = 0; i<n; i++){
            int x = pref[i];

            if(mp.find(x-target) != mp.end()){
                res+= mp[x-target];
            }
            
            mp[pref[i]]++;
        }


        cout<<res<<endl;
    }

    signed main(){

        solve();
    }