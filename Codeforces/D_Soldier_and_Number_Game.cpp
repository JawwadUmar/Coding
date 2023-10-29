#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main(){

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int sz = 2301;

    vector<int> dp (5000001, 1);
    vector<bool> v(sz, 1);
    

    v[1] = 0;
    
    for(int i = 2; i*i <= 2300; i++){

        if(v[i] ==0){
            continue;
        }

        for(int j = i*i; j <= 2300; j+=i){
            v[j] = 0;
        }
    }

    vector<int> primes;

    for(int i = 1; i<=sz; i++){
        if(v[i] ==1){
            primes.push_back(i);
        }
    }
    for(int i = 2; i<=(5000000); i++){

        for(int x :primes){
            if(x*x <= i){
                if(i%x == 0){
                    dp[i] = 1 + dp[i/x];
                    break;
                }
            }

            else{
                break;
            }
        }  
    }

    dp[0] = 0;
    dp[1] = 0;

    for(int i = 1; i<=5000000; i++){
        dp[i] += dp[i-1];
    }
    
    int t = 1;
    cin>>t;

    while(t--){

    int a, b;
    cin>>a>>b;

    cout<<dp[a] - dp[b]<<endl;

    }
    
    return 0;
}