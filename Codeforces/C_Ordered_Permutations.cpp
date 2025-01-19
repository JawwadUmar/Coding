#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int n, k;
    cin>>n>>k;

    if(((n-1) <= 63) && (1ll<<(n-1) < k)){
        cout<<-1<<endl;
        return;
    }

    vector<int> res(n);
    int i = 0;
    int j = n-1;
    
    int test_value = n-2;

    for(int num = 1; num<=n; num++){

        //if put at the ith position the k should be within 2^n-1
        long long x = 1e18;
        if(test_value <=63){
            x = (1ll<<test_value);
        }

        if(k<= x){
            res[i] = num;
            i++;
        }

        else if(test_value > 63){
            res[i] = num;
            i++;
        }

        else{
            res[j] = num;
            k = k-x;
            j--;
        }

        test_value--;
    }

    for(auto it: res){
        cout<<it<<" ";
    }
    cout<<endl;
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
