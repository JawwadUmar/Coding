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


void print(vector<vector<char>> &v){

    int n = v.size();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<v[i][j];
        }

        cout<<endl;
    }
}


int findIndex(int idx, vector<int> &v, int val){

    int low = idx;
    int high = v.size()-1;

    int res = -1;


    while (high >= low)
    {
        int mid = (low + high)/2;

        if(v[mid] < val){
            res = mid;
            low = mid+1;
        }

        else{
            high = mid-1;
        }
    }

    return res;
    
}
void solve(){

    int n;
    cin>>n;

    vector<int> a(n);
    map<int,int> mp;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    vector<pair<int, int>> tempEven;
    vector<int> tempodd;

    for(auto it: mp){
        if(it.second != 1){
            if((it.second)%2 == 0){
                tempEven.push_back({it.first, it.second});
            }

            else{
                tempEven.push_back({it.first, it.second-1});
                tempodd.push_back(it.first);
            }
        }

        else{
            tempodd.push_back(it.first);
        }
    }

    if(tempEven.empty()){
        cout<<0<<endl;
        return;
    }

    //can choose at most two sides from tempodd 
    int sumSide = 0;
    int cnt = 0;
    
    for(auto it: tempEven){
        sumSide+= it.first*it.second;
        cnt+= it.second;
    }

    sort(tempodd.begin(), tempodd.end());

    int x, y;
    x = y = -1e18;
    for(int i = 0; i<tempodd.size(); i++){
        if(tempodd[i] < sumSide){
            x = tempodd[i];
        }
    }

    if(x!= y){
        cnt++;
    }

    int res1 = 0;

    if(cnt >=3){
        res1 = max(x +sumSide, sumSide);
    }

    x = y = 0;

    for(int i =0; i<tempodd.size(); i++){
         y= tempodd[i];

        int idx = findIndex(i+1, tempodd, sumSide+ y);

        if(idx == -1){
            continue;
        }
         x = tempodd[idx];
         cnt++;

        res1 = max(res1, sumSide + x + y);
    }

    if(cnt>=3){
        cout<<res1<<endl;
    }

    else{
        cout<<0<<endl;
    }

    

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