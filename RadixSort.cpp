#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int>&a, int digitPlace){

    vector<int> count(10, 0);
    digitPlace = pow(10, digitPlace);
    for(int x: a){
        int digit = (x/digitPlace)%10;
        count[digit]++;
    }

    for(int i = 1; i<10; i++){
        count[i]+= count[i-1];
    }

    int n = a.size();
    vector<int> res(n);

    for(int i = n-1; i>=0; i--){
        int x = a[i];
        int digit = (x/digitPlace)%10;
        int index = count[digit]-1;
        res[index] = a[i];
        count[digit]--;
    }

    a = res;
}
void radixSort(vector<int> &a){
    int n = a.size();
    int mxElement = *max_element(a.begin(), a.end());
    int totalDigits = log10(mxElement) +1;

    for(int digitPlace = 0; digitPlace< totalDigits; digitPlace++){

        countSort(a, digitPlace);
    }
}

int main(){
    // vector<int> a = {6, 33, 324, 53, 56, 543};
    vector<int> a = { 170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(a);

    for(int elem: a){
        cout<<elem<<" ";
    }
    cout<<endl;
}