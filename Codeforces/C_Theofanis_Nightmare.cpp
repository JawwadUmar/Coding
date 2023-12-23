    #include <bits/stdc++.h>
    using namespace std;

    #define int long long
    #define endl '\n'

    void solve(){

        int n;
        cin>>n;

        vector<int> a(n);

        for(int i = 0; i<n; i++){
            cin>>a[i];
        }

        vector<int> suff(n);

        suff[n-1] = a[n-1];

        for(int i = n-2; i>=0; i--){
            suff[i] = suff[i+1] + a[i];
        }

        int res = suff[0];

        for(int i = 1; i<n; i++){
            if(suff[i]> 0){
                res+= suff[i];
            }
        }

        cout<<res<<endl;
    }

    signed main(){

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;

        while (t--)
        {
            solve();
        }
        
    }