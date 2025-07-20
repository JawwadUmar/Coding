#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int f(vector<int>& weights, int idx){

    for(int i = idx-1; i>=0; i++){
        
    }
}
int maxBalancedShipments(vector<int>& weights) {
    int n = weights.size();
    if(n == 0){
        return 0;
    }

    int res = (n*(n+1))/2;
    for(int i = 0; i<n; i++){
        int total = f(weights, i);
        res-= total;
    }

    cout<<res<<endl;
}

// Driver code
int main() {
    // vector<int> weights = {8, 6, 4, 7, 2};  // Sample input
    // vector<int> weights = {1, 2, 3, 2, 6, 3};  // Sample input
    vector<int> weights = {4, 3, 6, 5, 3, 4, 7, 1};  // Sample input
    int result = maxBalancedShipments(weights);
    cout << "Maximum number of balanced shipments: " << result << endl;
    return 0;
}
