#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int partition(vector<int>& arr, int low, int high) {
        
        int pivot = arr[high];
        
        //first bigger element
        int pidx = -1;
        for(int i = low; i<high; i++){
            if(arr[i] > pivot){
                pidx = i;
                break;
            }
        }
        
        if(pidx == -1){
            return high;
        }
        
        for(int i = pidx; i<high; i++){
            if(arr[i] < pivot){
                swap(arr[i], arr[pidx]);
                pidx++;
            }
        }
        
        swap(arr[pidx], arr[high]);
        
        return pidx;
}

void quickSort(vector<int>& arr, int low, int high) {
        // code here
        
        if(low > high){
            return;
        }
        
        int pidx = partition(arr, low, high);
        quickSort(arr,low, pidx-1);
        quickSort(arr,pidx+1, high);
    }


// Example usage
signed main() {
    
    int x = 1e18;
    int nextPow = log2(x);
    cout<<nextPow<<endl;
}