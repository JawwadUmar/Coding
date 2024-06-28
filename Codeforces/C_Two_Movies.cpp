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

    int n;
    cin>>n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }

    //a -> -1 0 1
    //b -> -1 0 1

    int bothNegative = 0;
    int bothPositive = 0;
    int A = 0;
    int B = 0;

    for(int i = 0; i<n; i++){
        if(a[i] ==-1 && b[i] == -1){
            bothNegative++;
        }

        else if(a[i] ==1 && b[i] ==1){
            bothPositive++;
        }

        else if(a[i] ==1 && b[i]<=0){
            A++;
        }

        else if(a[i]<=0 && b[i] ==1){
            B++;
        }
    }

    while (bothNegative)
    {
        if(A>B){
            A--;
        }

        else{
            B--;
        }

        bothNegative--;
    }

    while (bothPositive)
    {
        if(A<B){
            A++;
        }

        else{
            B++;
        }

        bothPositive--;
    }

    cout<<min(A, B)<<endl;
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