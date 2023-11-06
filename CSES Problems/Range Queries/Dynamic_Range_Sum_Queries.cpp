//FENWICK TREE
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void upadateFenwick(int idx, int val, vector<int> &Fenwick){

    while (idx < Fenwick.size())
    {
        Fenwick[idx]+= val;
        idx = idx + (idx &(-idx));
    }
    
}

int prefSum(int idx, vector<int> &Fenwick){

    int sum = 0;

    while (idx>0)
    {
        sum+= Fenwick[idx];
        idx = idx - (idx &(-idx));
    }

    return sum;
    
}



signed main(){

    int n;
    cin>>n;

    int q;
    cin>>q;

    vector<int> a(n+1);

    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }

    vector<int> Fenwick (n+1, 0);

    for(int i = 1; i<=n; i++){
        upadateFenwick(i, a[i], Fenwick);
    }
    

    for(int i = 0; i<q; i++){

        int qtype;
        cin>>qtype;

        if(qtype == 1){
            int idx, val;
            cin>>idx>>val;

            int prev = a[idx];
            int diff = val - prev;
            a[idx] = val;

            upadateFenwick(idx, diff, Fenwick);
        }
 
        else{
            int l, r;
            cin>>l>>r;

            cout<< prefSum(r, Fenwick) - prefSum(l-1, Fenwick)<<endl;
        }
    }

}