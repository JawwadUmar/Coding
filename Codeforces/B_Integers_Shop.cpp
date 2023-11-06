#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve(){

    int n;
    cin>>n;

    vector<vector<int>> v;

    for(int i = 0; i<n; i++){
        int l, r, c;
        cin>>l>>r>>c;

        v.push_back({l, r, c});
    }


    int mxLen = 0;
    int mxLenCost = INT_MAX;

    int mnL = INT_MAX;
    int mxR = INT_MIN;

    int costL = INT_MAX;
    int costR = INT_MAX;

    for(int i = 0; i<n; i++){

        int l = v[i][0];
        int r = v[i][1];
        int c = v[i][2];

        int cost;

        if(r-l+1 >= mxLen){

            if(r-l+1 > mxLen){
                mxLen = r-l+1;
                mxLenCost = c;
            }

            else{
                mxLenCost = min(mxLenCost, c);
            }
        }

        if(l<= mnL){
            if(l==mnL){
                costL = min(costL, c);
            }

            else{
                costL = c;
            }

            mnL = l;
            
        }

        if(r>= mxR){
            if(r == mxR){
                costR = min(costR, c);
            }

            else{
                costR = c;
            }

            mxR = r;
        }


        if(mxLen == mxR-mnL+1){
            cost = min(mxLenCost, costL+costR);
        }

        else{
            cost = costL + costR;
        }

        cout<<cost<<endl;
    }


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