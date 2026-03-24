#include <bits/stdc++.h>
using namespace std;

class Fancy {
private:
int MOD = 1e9+7;
int binExp(int a, int p){
    if(p == 0){
        return 1;
    }

    int res = binExp(a, p/2);
    res = (res*1ll*res)%MOD;

    if(p%2==1){
        res = (res*1ll*a)%MOD;
    }

    return res%MOD;
}

public:
    
    vector<long long> v;
    long long a = 0;
    long long m = 1;
    Fancy() {
    }
    
    void append(int val) {
        
        long long valToAdd = (((val - a + MOD)%MOD) *1ll* binExp(m, MOD-2))%MOD;
        v.push_back(valToAdd);
    }
    
    void addAll(int inc) {
        a = (a + inc)%MOD;
    }
    
    void multAll(int mul) {
        a = (a*mul)%MOD;
        m = (m*mul)%MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= v.size()){
            return -1;
        }

        return (m*v[idx] + a)%MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */