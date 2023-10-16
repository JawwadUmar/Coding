#include <bits/stdc++.h>
using namespace std;
#define int long long

// void f(int idx, vector<int>&a, int sum,int totalsum, int &minm){
//     int n = a.size();

//     if(idx == n){
//         // minm = min((totalsum-sum),sum);
//         minm = min(minm, abs(totalsum-sum-sum));
//         return;
//     }

//     f(idx+1, a,sum+a[idx], totalsum, minm);
//     f(idx+1,a, sum, totalsum, minm);
// }

// void f(int idx, vector<int> &a, vector<int> &res, int &sum){
//     int n = a.size();

//     if(idx ==n){
//         res.push_back(sum);
//         return;
//     }

//     sum+= a[idx];
//     f(idx+1, a, res, sum);

//     sum-= a[idx];

//     f(idx+1, a, res, sum);

// }

signed main(){
    int n;
    cin>>n;

    vector<int> a(n);
    int totalsum =0;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int diff = INT_MAX;

    for(int i= 0; i<pow(2, n); i++){
        int sum1 = 0;
        int sum2 = 0;

        for(int j =0; j<n; j++){
            if((1<<j)&i){
                sum1+= a[j];
            }

            else{
                sum2+= a[j];
            }
        }

        diff = min(diff, abs(sum1-sum2));
    }
    
    cout<<diff<<endl;
}