#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    int findRightMostSmallerIndex(int val, int low, vector<int> &suffixSmaller){
        int high = suffixSmaller.size()-1;
        int res = low;

        while(high>= low){
            int mid = (low+high)/2;
            if(suffixSmaller[mid] < val){
                res = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return res;
    }

    int findBiggestLeftValue(int idx, vector<int> &prefixBigger){
        return prefixBigger[idx];
    }

public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixSmaller(n);

        suffixSmaller[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            suffixSmaller[i] = min(nums[i], suffixSmaller[i+1]);
        }

        vector<int> prefixBigger(n);
        prefixBigger[0] = nums[0];

        for(int i =1; i<n; i++){
            prefixBigger[i] = max(prefixBigger[i-1], nums[i]);
        }

        vector<int> res(n);

        for(int i = 0; i<n; i++){
            int rightMostSmallerIndex = findRightMostSmallerIndex(nums[i], i, suffixSmaller);
            int biggestLeftValue = findBiggestLeftValue(rightMostSmallerIndex, prefixBigger);
            res[i] = biggestLeftValue;
        }

        return res;
    }
};