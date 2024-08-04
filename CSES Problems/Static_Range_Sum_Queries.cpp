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

void buildTree(int idx, int l, int r, vector<int>& nums, vector<int> &segTree){
        if(l == r){
            segTree[idx] = nums[l];
            return;
        }

        int mid = (l+r)/2;

        buildTree(2*idx+1, l, mid, nums, segTree);
        buildTree(2*idx+2, mid+1, r, nums, segTree);

        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
}

int query(int idx, int st, int end, int l, int r, vector<int> &segTree){
        //out of bound
        if(r<st || l>end){
            return 0;
        }

        //complete inside
        if(l>=st && r<=end){
            return segTree[idx];
        }

        //partial
        int mid = (l+r)/2;
        int a =query(2*idx+1, st, end, l, mid, segTree);
        int b =query(2*idx+2, st, end, mid+1, r, segTree);

        return a+b;
    }


void solve(){

    int n, q;
    cin>>n>>q;
    
    vector<int> nums(n);

    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }

    vector<int> segTree(4*n);
    buildTree(0, 0, n-1, nums, segTree);

    while (q--)
    {
        int st, en;
        cin>>st>>en;

        cout<<query(0, st-1, en-1, 0, n-1, segTree)<<endl;
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}