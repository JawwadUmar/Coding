#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

const double EPS = 1e-9;  // Tolerance for double comparisons

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    if(n == 1 || n == 2){
        cout << 0 << endl;
        return;
    }

    vector<pair<double, double>> v;

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            double cd = (double)(a[j] - a[i]) / double(j-i);
            double firstTerm = (double)(a[i]) - (double)(i * cd);
            v.push_back({firstTerm, cd});
        }
    }

    int res = INT_MAX;

    for(int itr = 0; itr < v.size(); itr++){
        double term = v[itr].first;
        double d = v[itr].second;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            // Compare with tolerance
            if(fabs((double)a[i] - term) > EPS){
                cnt++;
            }

            term += d;
        }

        res = min(res, cnt);
    }

    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
