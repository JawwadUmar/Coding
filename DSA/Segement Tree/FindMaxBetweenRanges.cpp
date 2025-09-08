#include <bits/stdc++.h>
using namespace std;
#define int long long


void buildTree(int idx, int low, int high, vector<int> &a, vector<int> &segTree){

    if(low == high){
        segTree[idx] = a[low];
        return;
    }

    int mid = (low+high)/2;

    buildTree(2*idx+1, low, mid, a, segTree);
    buildTree(2*idx+2, mid+1, high, a, segTree);

    segTree[idx] = max(segTree[2*idx+1], segTree[2*idx+2]);
}


int queryInTree(int idx, int l, int r, int low, int high, vector<int> &segTree){

    if(low>= l && high<=r){
        return segTree[idx];
    }

    if(high < l || low > r){
        return -(1e18);
    }

    int mid = (low+high)/2;

    int leftNode = queryInTree(2*idx+1, l ,r, low, mid, segTree);
    int rightNode = queryInTree(2*idx+2, l, r, mid+1, high, segTree);

    return max(leftNode, rightNode);

}
void solve(){
    int n;
    cin>>n;

    int q;
    cin>>q;


    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    vector<int> segTree(4*n);

    buildTree(0, 0, n-1, a, segTree);

    while (q--)
    {
        int l, r;
        cin>>l>>r;
        l--;
        r--;

        cout<<queryInTree(0, l, r, 0, n-1, segTree)<<endl;
    }

    
    

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    
}