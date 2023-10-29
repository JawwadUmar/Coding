#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;

    int m;
    cin>>m;

    vector<pair<int, int>> v;
    vector<int> a(n);

    for(int i = 0; i<n; i++){
        int x;
        cin>>x;

        a[i] = x;

        v.push_back({x, i+1});
    }

    sort(v.begin(), v.end());

    int cnt =1;

    int i = 1;
    int lastidx = v[0].second;

    while (i<n)
    {
        if(v[i].second < lastidx){
            cnt++;
        } 

        lastidx = v[i].second;
        i++;
    }

    while (m--)
    {
        int ind1, ind2;
        cin>>ind1>>ind2;

        ind1--;
        ind2--;

        if(ind1 > ind2){
            swap(ind1, ind2);
        }

        if(a[ind1] > a[ind2]){
            cnt--;
            cout<<cnt<<endl;
        }

        else{
            cnt++;
            cout<<cnt<<endl;
        }

        swap(a[ind1], a[ind2]);

        for(auto it: a){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    
    
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

}