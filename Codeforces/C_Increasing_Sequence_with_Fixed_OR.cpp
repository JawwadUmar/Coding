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

string convertToBitString(int n){
    string s = "";
    while (n)
    {
        if(n%2){
            s+="1";
        }

        else{
            s+="0";
        }

        n = n/2;
    }

    reverse(s.begin(), s.end());

    return "0" + s;
}

int stringToInt(string &s){
    int ans = 0;
    int j = 0;

    for(int i = s.size()-1; i>=0; i--){
        if(s[i] == '1'){
            ans = ans + (1<<j);
        }
        j++;
    }

    return ans;
}


void solve(){
    int n;
    cin>>n;

    string s = convertToBitString(n);
    vector<string> v;
    v.push_back(s);

    string temp = s;

    for(int i = s.size()-1; i>=0; i--){
        if(temp[i] == '1'){
            temp[i] = '0';
            v.push_back(temp);
            temp[i] = '1';
        }
    }
    
    vector<int> ans;

    for(auto it: v){
        int x = stringToInt(it);
        if(x>0){
            ans.push_back(x);
        }
    }

    reverse(ans.begin(), ans.end());

    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it<<" ";
    }

    cout<<endl;
    
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