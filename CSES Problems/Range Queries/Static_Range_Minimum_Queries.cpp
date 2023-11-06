#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void buildTree(int idx, int low, int high, vector<int> &a, vector<int> &segTree){

    if(low == high){
        segTree[idx] = a[low];
        return;
    }

    if(low> high){
        return;
    }

    int mid = (low+high)/2;

    buildTree(2*idx+1, low, mid, a, segTree);
    buildTree(2*idx+2, mid+1, high, a, segTree);

    segTree[idx] = min(segTree[2*idx+1], segTree[2*idx+2]);
}


int query(int idx, int l, int r, int low, int high, vector<int> &segTree){

    if(l>high || r < low){
        return 1e18;
    }

    if(l<=low && r>=high){
        return segTree[idx];
    }

    int mid = (low+high)/2;

    int left = query(2*idx+1, l, r, low, mid, segTree);
    int right= query(2*idx+2, l, r, mid+1, high, segTree);

    return min(left, right);
}


void solve(){
    int n, q;
    cin>>n>>q;

    vector<int> a(n+1);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    vector<int> segTree(4*n, 1e18);

    buildTree(0, 0, n-1, a, segTree);

    for(int i = 0; i<q; i++){
        int l, r;
        cin>>l>>r;
        l--;
        r--;

        cout<<query(0, l ,r, 0, n-1, segTree)<<endl;
    }




}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}