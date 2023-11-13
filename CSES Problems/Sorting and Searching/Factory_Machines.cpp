#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

bool f(int mid, vector<int> &a, int m){

    int cnt = 0;

    for(int i = 0; i<a.size(); i++){
        cnt+= mid/a[i];

        if(cnt>= m){
            return true;
        }
    }

    return cnt>=m;
}


void solve(){

    int n, m;
    cin>>n>>m;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    int high = 1e18;
    int low = 0;
    int res = 1e18;

    while (high>=low)
    {
        int mid = (low+high)/2;

        if(f(mid, a, m)){
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

    solve();
}