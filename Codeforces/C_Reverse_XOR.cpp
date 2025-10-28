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



int calc(string &s){
    int n = s.size();
    int res = 0;
    int cnt = 0;
    for(int i = n-1; i>=0; i--){
        
        if(s[i] == '1'){
            res = (res | (1<<cnt));
        }

        cnt++;
    }

    return res;
}


string generate(int num){
    string res;

    while (num)
    {
        if(num%2){
            res.push_back('1');
        }

        else{
            res.push_back('0');
        }

        num = num/2;
    }

    reverse(res.begin(), res.end());

    return res;
    
}

void solve(){

    int n;
    cin>>n;

    int temn = n;
    int countbits = 0;

    while (n)
    {
        if(n%2){
            countbits++;
        }

        n =n/2;
    }

    n = temn;

    if(countbits%2 != 0){
        cout<<"NO"<<endl;
        return;
    }


    for(int i = 0; i<=1000000; i++){
        string temp = generate(i);
        int x1 = calc(temp);
        reverse(temp.begin(), temp.end());
        int x2 = calc(temp);

        // cout<<x1<<endl;

        if((x1^x2) == n){
            cout<<"YES"<<endl;
            return;
        }

        
    }

    cout<<"NO"<<endl;

    

    

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