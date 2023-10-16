    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    int MOD = 1e9+7;
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


    void solve(){

        int a, b, c;
        cin>>a>>b>>c;
        // cout<<"here"<<endl;

        int sum = a+b+c;

        if(sum%3 != 0 && sum%4 != 0 && sum%5 !=0 && sum%6 != 0){
            cout<<"NO"<<endl;
            return;
        }

        //  cout<<"here"<<endl;

        if(sum%3 == 0){
            if(a == b && b==c){
                cout<<"YES"<<endl;
                return;
            }
        }
        //  cout<<"here"<<endl;

        multiset<int> m;
        m.insert(a);
        m.insert(b);
        m.insert(c);
        //  cout<<"here"<<endl;

        auto it1 = --(m.end());
        int largest = *it1;
        // cout<<largest<<endl;

        auto it2 = m.begin();
        int smallest = *it2;
        // cout<<smallest<<endl;

        if(largest == smallest){
            cout<<"YES"<<endl;
            return;
        }

        //1 cut
        largest = largest -smallest;
        m.erase(it1);
        m.insert(largest);
        m.insert(smallest);

        it1 = --(m.end());
        it2 = m.begin();

        largest = *it1;
        smallest = *it2;

        //  for(auto it: m){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        if(largest == smallest){
            cout<<"YES"<<endl;
            return;
        }

        //2 cut
        largest = largest -smallest;
        m.erase(it1);
        m.insert(largest);
        m.insert(smallest);

        it1 = --(m.end());
        it2 = m.begin();

        largest = *it1;
        smallest = *it2;

        //  for(auto it: m){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        if(largest == smallest){
            cout<<"YES"<<endl;
            return;
        }


        //3 cut
        largest = largest -smallest;
        m.erase(it1);
        m.insert(largest);
        m.insert(smallest);

        it1 = --(m.end());
        it2 = m.begin();

        largest = *it1;
        smallest = *it2;

        //  for(auto it: m){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        if(largest == smallest){
            cout<<"YES"<<endl;
            return;
        }

        cout<<"NO"<<endl;


        
    }

    signed main(){
        ios_base::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);
        
        int t;
        cin>>t;
        while(t--){
        solve();
        }
        return 0;
    }