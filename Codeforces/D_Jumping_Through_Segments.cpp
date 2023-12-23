#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


bool f(int mid, vector<int> &l, vector<int> &r){

    int left = 0;
    int right = mid;

    int n = l.size();

    for(int i =0; i<n; i++){
        if(l[i] > right || left > r[i]){
            return false;
        }

        left = max(left, l[i]);
        right = min(right, r[i]);

        //for next move
        left = max(0ll, left-mid);
        right = right+mid;
    }

    return true;
}

void solve(){

    int n;
    cin>>n;

    vector<int> l(n);
    vector<int> r(n);

    for(int i = 0; i<n; i++){
        cin>>l[i]>>r[i];
    }

    int high = 1e18;
    int low = 0;

    int res = -1;

    while (high>= low)
    {
        int mid = high - (high - low)/2;

        if(f(mid, l, r)){
            res = mid;
            high = mid-1;
        }

        else{
            low = mid+1;
        }
    }

    cout<<res<<endl;
    

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while (t--)
    {
        solve();
    }
    

}