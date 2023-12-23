#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){

    int n, k;
    cin>>n>>k;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }


    //with atmost k distinct subarrays....

    //with at least k+1 distinct subarrays .....

    int i = 0;
    int j = 0;

    int temp = k+1;

    int cnt = 0;

    map<int, int> mp;
    int res = 0;

    while (j<n)
    {
        mp[a[j]]++;

        while (mp.size() > k)
        {
            mp[a[i]]--;

            if(mp[a[i]] == 0){
                mp.erase(a[i]);
            }
            i++;
        }

        if(mp.size() <=k){
            cout<<i<<" "<<j<<endl;
            cnt++;
        }


        j++;
    }


    cout<<cnt<<endl;
     
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}