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


void solve(){

    int a, n;
    cin>>a>>n;

    vector<int> d;

    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        d.push_back(x);
    }

    sort(d.begin(), d.end());

    int totalDigits = 0;
    int temp = a;

    while (temp)
    {
        totalDigits++;
        temp = temp/10;
    }


    
    //same no of digits
    string num = to_string(a);

    string p1 = "";
    for(int i = 0; i<totalDigits; i++){
        char currentDigit = num[i];
        int diff = 1e9;
        char accept;

        for(int j = 0; j<d.size(); j++){
            int dig = d[j];
            char ch_dig = dig + '0';
            int currdiff = abs(ch_dig - currentDigit);
            if(currdiff < diff){
                accept = ch_dig;
                diff = currdiff;
            }
        }

        p1.push_back(accept);
    }

    int res = abs(stoll(p1) - a);

    //lesser no of digits
    string p2 = "";

    for(int i = 0; i<totalDigits-1; i++){
        p2+= to_string(d.back());
    }

    if(p2.size() != 0){
        res = min(res, abs(stoll(p2) - a));
    }
    
    
    //more no of digits
    string p3 = "";
    for(int i = 0; i<=totalDigits; i++){
        p3+= to_string(d.back());
    }

    if(p3.size() != 0){
        res = min(res, abs(stoll(p3) - a));
    }

    cout<<res<<endl;


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