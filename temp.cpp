#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int reverseBits(int n) {
        
        int temp = n;
        vector<int> v;
        while (n!=0)
        {
            int rem = n%2;
            v.push_back(rem);
            n = n/2;
        }

        while (v.size() != 32)
        {
            v.push_back(0);
        }
        
        int res = 0;
        int j = 0;
        for(int i = v.size()-1; i>=0; i--){
            if(v[i] == 1){
                res = (res | (1<<j));
            }

            j++;
        }
        
        return res;
    }
};