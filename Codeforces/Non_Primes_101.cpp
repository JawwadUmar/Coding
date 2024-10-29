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

void sieveofErastosThenes(vector<int> &isPrime){
    isPrime[0] = 0;
    isPrime[1] = 0;

    for(int i = 2; i*i<=200; i++){

        if(isPrime[i]){

            for(int j = i*i; j<=200; j+=i){
                isPrime[j] = 0;
            }
        }
        
    }
}

void solve(vector<int> &isPrime){

    int n;
    cin>>n;

    vector<int> a(n);
    map<int, int> mp;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    // for(int i = 1; i<=15; i++){
    //     cout<<i<<" "<<isPrime[i]<<endl;
    // }

    int idx1 = -1;
    int idx2 = -1;

    for(int i = 0; i<n; i++){
        int x = a[i];

        for(int j = 1; j<=200; j++){
            if(isPrime[j] == 0){
                
                int y = j-a[i];
                

                if(y>=1 && y<=100){
                //     if(i==0){
                //     cout<<a[i]<<" "<<j<<endl;
                // }
                    if(y == x){
                        if(mp[y] <=1){
                            continue;
                        }

                        else{
                            idx1 = i;
                            break;
                        }
                    }

                    else if(mp[y]>=1){
                        idx1= i;
                        break;
                    }
                }
            }
        }

        if(idx1 != -1){
            break;
        }
    }

    if(idx1 == -1){
        // cout<<"here"<<endl;
        cout<<-1<<endl;
        return;
    }

    // cout<<idx1<<endl;

    for(int i = idx1+1; i<n; i++){
        int x = a[idx1] + a[i];

        if(isPrime[x] ==0){
            cout<<idx1+1<<" "<<i+1<<endl;
            return;
        }
    }

    cout<<-1<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    vector<int> isPrime(201, 1);
    sieveofErastosThenes(isPrime);
    set<int> PrimeNumbers;

    int t = 1;
    cin>>t;
    while(t--){
       solve(isPrime);
    }
    return 0;
}