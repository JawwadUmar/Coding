#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int binaryExponentiation(int x, int p){
    int res = 1;
    while(p){
        if(p%2){
            res = (res * x);
        }

        x = (x*x);
        p = p/2;
    }
    
    return res;
}


void solve(vector<int> &low_limit, vector<int> &up_limit){
    int q;
    cin>>q;

    while (q--)
    {
        int n;
        cin>>n;

        if(n<=9){
            cout<<n<<endl;
            continue;
        }

        auto it_low = lower_bound(low_limit.begin(), low_limit.end(), n);

        if(it_low == low_limit.end()){
            // cout<<"yhn"<<endl;
            it_low = --(low_limit.end());
        }

        else if(*it_low != n){
            it_low--;
        }

        auto it_up = lower_bound(up_limit.begin(), up_limit.end(), n);

        int digit = (it_up - up_limit.begin()) + 1;

        int extra = n - *it_low;
        int rem = extra%digit;
        int q = extra/digit;

        int start = binaryExponentiation(10, digit-1);
        start = start+q;

        string temp = to_string(start);

        cout<<temp[rem]<<endl;

    }

// 1 9
// 10 189
// 190 2889
// 2890 38889
// 38890 488889
// 488890 5888889
// 5888890 68888889
// 68888890 788888889
// 788888890 8888888889
// 8888888890 98888888889
// 98888888890 1088888888889
// 1088888888890 11888888888889
// 11888888888890 128888888888889
// 128888888888890 1388888888888889
// 1388888888888890 14888888888888889
// 14888888888888890 158888888888888889
// 158888888888888890 1688888888888888889
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    vector<int> sz;
    int cnt = 9;
    int idx = 1;

    while (1)
    {
        if (cnt > LLONG_MAX / idx) {
        break;
    }
        int temp = cnt*idx;
        sz.push_back(temp);
        
        cnt = cnt*10;

        idx++;
    }

    // for(auto it: sz){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    vector<int> low_limit;
    vector<int> up_limit;

    up_limit.push_back(9);

    for(int i = 1; i<sz.size(); i++){
        int temp = sz[i] + up_limit.back();
        up_limit.push_back(temp);
    }

    // for(auto it: up_limit){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    low_limit.push_back(1);

    for(int i = 0; i<sz.size()-1; i++){
        int temp = sz[i] + low_limit.back();

        low_limit.push_back(temp);
    }

    // for(auto it: low_limit){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    // map<int, int> mp;

    // for(int i = 0; i<low_limit.size(); i++){
    //     cout<<low_limit[i]<<" "<<up_limit[i]<<endl;
    //     // mp[low_limit[i]] = i+1;
    //     // mp[up_limit[i]] = i+1;
        
    // }

    solve(low_limit, up_limit);

    return 0;
}



// 9 180 2700 36000 450000 5400000 63000000 720000000 8100000000 90000000000 990000000000 10800000000000 117000000000000 1260000000000000 13500000000000000 144000000000000000 1530000000000000000 -2246744073709551616