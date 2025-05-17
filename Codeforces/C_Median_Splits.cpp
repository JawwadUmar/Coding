#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>



using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long




int binaryExponentiation(int x, int p){
    int res = 1;
    while(p){
        if(p%2){
            res = (res * x)%MOD;
        }

        x = (x*x)%MOD;
        p = p/2;
    }
    
    return res;
}


class MedianMaintainer {
    priority_queue<int> maxHeap; // lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // upper half

public:
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double getMedian() {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        return maxHeap.top();
    }

    void clear() {
        maxHeap = priority_queue<int>();
        minHeap = priority_queue<int, vector<int>, greater<int>>();
    }
};


void solve(){

    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<int> a(n);
    vector<int> prefMed(n);
    vector<int> suffMen(n);

    for(int i =0; i<n; i++){
        cin>>a[i];
    }

    multiset<int> m1;
    multiset<int, greater<int>()> m2;

    for(int i = 0; i<n; i++){
        m1.insert(a[i]);
        m2.insert(a[i]);

        auto it1 = m1.begin();
        auto it2 = m2.begin();

        if(*it1 == *it2){
            prefMed[i] = *it1;
            continue;
        }

        else if()
    }

    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}