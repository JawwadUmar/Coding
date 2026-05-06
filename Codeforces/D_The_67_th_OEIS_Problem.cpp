#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;

    // b1, b2, b3, ...., bn, bn+1
    //gcd(ai, ai+1) = bi+1 * gcd(bi, bi+2)
    //all bi must be distinct and bi & bi+2 should be co prime
    //1, 3, 5, 7, 9, 11, ...
    int b1 = 1;
    

    for(int i = 0; i<n; i++){
        int b2 = b1 + 2;
        cout<<b1*b2<<" ";
        b1 = b2;
    }
    cout<<endl;
}

int main(){

    int t;
    cin>>t;

    while (t--)
    {
        solve();
    }
    

}

