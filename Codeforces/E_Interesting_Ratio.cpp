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


void sieveOfErastosthenes(vector<bool> &isPrime){
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i*i<=10000000; i++){
        
        if(isPrime[i] == true){
            int j = i*i;

            while (j<=10000000)
            {
                isPrime[j] = false;
                j+=i;
            }
            
        }
    }
}

void solve(vector<int> &primeNumbers){

    int n;
    cin>>n;

    int res = 0;

    for(int i= 1; i<=n; i++){
        int a = i;

        int prime = n/a;
        

        auto it = upper_bound(primeNumbers.begin(), primeNumbers.end(), prime);

        res+= (it - primeNumbers.begin());
    }

    cout<<res<<endl;

    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    vector<bool> isPrime(10000000+1, true);
    sieveOfErastosthenes(isPrime);
    
    vector<int> primeNumbers;

    for(int i = 2; i<= 10000000; i++){
        if(isPrime[i] == true){
            primeNumbers.push_back(i);
        }
    }
    
    int t = 1;
    cin>>t;
    while(t--){
       solve(primeNumbers);
    }
    return 0;
}