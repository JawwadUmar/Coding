    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int MOD = 1e9+7;
    #define endl '\n'
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;


    template <typename T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    template <typename T>



    using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

    #define int long long




    int binaryExponentiation(int x, int p){
        int res = 1;
        while(p){
            if(p%2){
                res = (res * x)%MOD;
            }

            x = (x*x)%MOD;
            p = p/2;
        }
        
        return res;
    }
    
    //ctrl shift B for output

    int numberOfSetBits(int n){
        return __builtin_popcount(n);
    }


    int isAlternating(string &s){
        char st = s[0];
        int cnt = 0;

        for(int i = 1; i<s.size(); i++){
            if(s[i] == st){
                cnt++;
            }

            st = s[i];
        }

        return cnt;
    }

    void solve(){

        string s;
        cin>>s;

        if(isAlternating(s) == 0){
            cout<<0<<endl;
            return;
        }

        int cnt0 = 0;

        for(auto it: s){
            if(it == '0'){
                cnt0++;
            }
        }

        int cnt1 = s.size() - cnt0;

        if(abs(cnt0 - cnt1) <= 1){
            cout<<1<<endl;
            return;
        }

        else if(abs(cnt0 - cnt1) <= 3){
            cout<<2<<endl;
        }


        else{
            cout<<3<<endl;
        }
        
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