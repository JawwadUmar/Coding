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


int countHash(vector<char> &v, char ch){
    int cnt = 0;

    for(char x: v){
        if(x == ch){
            cnt++;
        }
    }

    return cnt;
}

void print(vector<int> a){
    for(int x: a){
        cout<<x<<" ";
    }
    cout<<endl;
}

void solve(){

    int n;
    cin>>n;

    int loyaltyFactor;
    cin>>loyaltyFactor;

    vector<int> a(n);

    vector<int> b;
    vector<int> c;

    int points = 0;

    for(int i = 0; i<n; i++){
        cin>>a[i];

        if(a[i] >= loyaltyFactor){
            b.push_back(a[i]);
            points+= a[i];
        }

        else{
            c.push_back(a[i]);
        }
    }

    
    vector<int> res = b;

    if(c.size() == 0){
        print(res);
        cout<<points<<endl;
        return;
    }



    sort(c.begin(), c.end());
    
    int low = 0;
    int high = c.size()-1;
    int sum = 0;
    
    // cout<<high<<" "<<low<<endl;

    while (high>= low)
    {
        sum+= c[low];
        res.push_back(c[low]);
        if(sum + c[high] >= loyaltyFactor && low != high){
            sum = (sum + c[high])%loyaltyFactor;
            points+= c[high];
            res.push_back(c[high]);
            high--;
        }

        low++;
        
    }

    cout<<points<<endl;
    print(res);
    

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