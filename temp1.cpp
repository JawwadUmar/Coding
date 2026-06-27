#include <bits/stdc++.h>
using namespace std;

bool isPossibleToPartition(vector<int> &temp, int k){
    int sum = 0;
    for(int i =0; i<temp.size(); i++){
        sum+=temp[i];
    }
    int leftSum = 0;

    for(int i = 0; i<temp.size(); i++){
        leftSum+=temp[i];
        int rightSum = sum - leftSum;

        if(abs(rightSum - leftSum) <=k){
            return true;
        }
    }

    return false;
}

char maxBalancedLength(int n, int k, vector<int> arr){

    int res = 0;
    vector<int> prefSum(n, 0);

    prefSum[0] = arr[0];
    for(int i =1; i<n; i++){
        prefSum[i] = prefSum[i-1] +arr[i];
    }

    int leftSum = 0;

    for(int i = 0; i<n; i++){
        leftSum+= 
        for(int j = i+1; j<n; j++){

        }
    }

    if(res == 0){
        return '0';
    }
    else if(res <=5){
        return '1';
    }
    else if(res <=15){
        return '2';
    }
    else if(res<=50){
        return '3';
    }
    else{
        return '4';
    }
}

int main(){
    vector<int> arr = {4, 2, 6, 1, 3, 5};
    int k =3;
    cout<<maxBalancedLength(arr.size(), k, arr);
}