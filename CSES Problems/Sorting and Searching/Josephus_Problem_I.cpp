#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

void solve(){
    int n;
    cin>>n;


    vector<int> temp;
    
    for(int i = 0; i<n; i++){
        temp.push_back(i+1);
    }

    vector<int> res;

    while (temp.size() > 1)
    {

        vector<int> survivors;
        int x = (temp.size()+1)/2;
        
        if(temp.size()%2 == 0){

            int idx = 0;
            while (x)
            {
                survivors.push_back(temp[idx]);
                idx = (idx+2)%(temp.size());
                x--;
            }

            idx = 1;

            while (idx< temp.size())
            {
                res.push_back(temp[idx]);
                idx+=2;
            }
        }

        else{

            int idx = 0;

            while (x)
            {
                survivors.push_back(temp[idx]);
                idx = (idx+2)%(temp.size());
                x--;
            }

            idx = 1;

            while (idx< temp.size())
            {
                res.push_back(temp[idx]);
                idx+=2;
            }

            reverse(survivors.begin(), survivors.begin() + survivors.size()-1);
            reverse(survivors.begin(), survivors.end());
        }

        temp = survivors;
    }

    res.push_back(temp[0]);

    for(auto it: res){
        cout<<it<<" ";
    }
    cout<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}