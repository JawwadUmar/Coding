#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findHeightReduced(long long t, int workerTime){
        long long high = 1e18;
        long long low = 0;
        long long res=  0;
        while (high>=low)
        {
            long long mid = high - (high - low)/2;
            if(workerTime*1ll*mid*(mid+1) <= 2*t){
                low = mid+1;
                res = mid;
            }
            else{
                high = mid-1;
            }
        }

        return res; 
    }

    bool possible(long long mid, int mountainHeight, vector<int>& workerTimes){

        long long heightReduced = 0;

        for(int i = 0; i<workerTimes.size(); i++){
            heightReduced+= findHeightReduced(mid, workerTimes[i]);
            if(heightReduced >= mountainHeight*1ll){
                return true;
            }
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long high = 1e18;
        long long low = 1;
        long long res;

        while (high>=low)
        {
            long long mid = high - (high - low)/2;
            if(possible(mid, mountainHeight, workerTimes)){
                res = mid;
                high = mid-1;
            }

            else{
                low = mid+1;
            }
        }

        return res;
        
    }
};