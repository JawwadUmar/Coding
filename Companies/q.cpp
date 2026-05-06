#include <bits/stdc++.h>
using namespace std;

// long getMaxRevenue(vector<int> supplierStock, long orders) {
//     sort(supplierStock.begin(), supplierStock.end(), greater<int>());
//     supplierStock.push_back(0); // sentinel

//     long long revenue = 0;
//     int n = supplierStock.size();

//     for (int i = 0; i < n - 1 && orders > 0; i++) {
//         long long curr = supplierStock[i];
//         long long next = supplierStock[i + 1];
//         long long count = i + 1; // number of suppliers at this level

//         long long diff = curr - next;
//         long long totalUnits = count * diff;

//         if (orders >= totalUnits) {
//             // Take all levels down to next
//             long long sum = (curr + next + 1) * diff / 2; // sum from next+1 to curr
//             revenue += sum * count;
//             orders -= totalUnits;
//         } else {
//             // Partial fill
//             long long fullLevels = orders / count;
//             long long remainder = orders % count;

//             long long high = curr;
//             long long low = curr - fullLevels;

//             long long sum = (high + low + 1) * fullLevels / 2;
//             revenue += sum * count;

//             revenue += remainder * low;
//             break;
//         }
//     }

//     return revenue;
// }



long long maxSubarraySum(vector<int> &arr) {
    long long res = arr[0];
  
  	for(int i = 0; i < arr.size(); i++) {
    	long long currSum = 0;
      
        // Inner loop for ending point of subarray
        for(int j = i; j < arr.size(); j++) {
        	currSum = currSum + arr[j];
          
            // Update res if currSum is greater than res
            res = max(res, currSum);
        }
    }
    return res;
}

long findMaxEfficiencyRating(int multiplier, vector<int> scores) {
    int n = scores.size();
    long long res = maxSubarraySum(scores);

    cout<<res<<endl;

    if(res > 0){
        res = res*multiplier;
    }
    else{
        res = (res + multiplier-1)/multiplier;
    }

    return res;
}
int main(){

    // Q1
    // vector<int> a = {2, 5};
    // cout<<getMaxRevenue(a, 4);
    // vector<int> a = {2, 8, 4, 10, 6};
    // cout<<getMaxRevenue(a, 20);

    // Q2
    vector<int> a = {5, -3, -3, 2, 4};
    cout<<findMaxEfficiencyRating(2, a)<<endl;
}