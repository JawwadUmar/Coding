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


bool isPossible(int x, vector<int> a, string &s, int k){

    //is it possbile to get a penalty lower than or equal to x
    int n = a.size();
    int i = 0;
    while (i<a.size() && k>0)
    {
        int j = i;
        if(s[i] == 'B'){
            if(a[i] > x){
                k--;
                while (j<n)
                {
                    if(s[j] == 'B'){
                        j++;
                    }

                    else if(a[j] <=x){
                        j++;
                    }

                    else{
                        break;
                    }
                }
                
            }
        }

        i = j+1;
    }

    if(i==n){
        return true;
    }

    int mxPenalty = 0;

    while (i<n)
    {
        if(s[i] =='B'){
            mxPenalty = max(mxPenalty, a[i]);
        }
        
        i++;
    }
    

    return x>=mxPenalty;
}

void solve(){

    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;

    vector<int> a(n);
    for(auto &it: a){
        cin>>it;
    }

    int cntblue = 0;
    int high_Penalty = 0;

    for(int i =0; i<s.size(); i++){
        if(s[i] == 'B'){
            cntblue++;
            high_Penalty = max(high_Penalty, a[i]);
        }
    }

    if(cntblue <= k){
        cout<<0<<endl;
        return;
    }

    // cout<<high_Penalty<<endl;

    int low_Penalty = 0;
    int res = high_Penalty;

    while (high_Penalty >= low_Penalty)
    {
        int mid = (high_Penalty+low_Penalty)/2;

        if(isPossible(mid, a, s, k)){
            res = min(res, mid);
            high_Penalty = mid-1;
        }

        else{
            low_Penalty = mid+1;
        }
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