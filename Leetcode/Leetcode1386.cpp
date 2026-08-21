#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTotalBlocks(set<int> &row){
        int res = 0;
        bool flag1 = (row.count(2) ==0 && row.count(3) ==0 && row.count(4) ==0 && row.count(5) ==0);
        bool flag2 = (row.count(6) ==0 && row.count(7) ==0 && row.count(8) ==0 && row.count(9) ==0);
        bool flag3 = (row.count(4) ==0 && row.count(5) ==0 && row.count(6) ==0 && row.count(7) ==0);

        if(flag1 && flag2){
            return 2;
        }
        else if(flag1 || flag2 || flag3){
            return 1;
        }

        return 0;

    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        set<int> reservedRows;
        map<int, set<int>> mp;
        for(vector<int> resv: reservedSeats){
            int r = resv[0];
            int c = resv[1];
            reservedRows.insert(r);
            mp[r].insert(c);
        }

        int remainingRows = n - reservedRows.size();
        int res = 2*remainingRows;

        cout<<"Remaining "<<res<<endl;

        for(int rows: reservedRows){
            cout<<rows<<" "<<findTotalBlocks(mp[rows])<<endl;
            res+= findTotalBlocks(mp[rows]);
        }

        return res;
        
    }
};