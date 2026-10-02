#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        int depth = 0;
        int n = seq.size();
        vector<int> res(n, -1);

        for(int i = 0; i<n; i++){
            
            if(seq[i] == '('){
                res[i] = (depth%2);
                depth++;
            }
            else if(seq[i] == ')'){
                depth--;
                res[i] = (depth%2);
            }
        }

        return res;

    }
};