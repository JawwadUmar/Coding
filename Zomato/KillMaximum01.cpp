#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'

vector<int> solution(const vector<int> &layers, const vector<int> &energy, long long k) {
    const int n = layers.size();
    vector<int> r(n);

    long long currentEnergy = k;
    int currentIndex = 0;

    int i = 0;
    while (i < n) {
        if (currentIndex <= i) {
            currentEnergy = k;
            currentIndex = i;
        }
        else {
            currentEnergy += layers[i - 1];
        }

        // cout<<i<<" "<<currentIndex<<" "<<currentEnergy<<endl;

        while (currentIndex < n && currentEnergy - layers[currentIndex] >= energy[currentIndex]) {
            currentEnergy -= layers[currentIndex];
            currentIndex++;
        }

        r[i] = currentIndex - i;
        i++;
    }

    return r;
}

void printArr(vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}


signed main(){
    // int n, k;
    // cin>>n>>k;

    // vector<int> layers(n);
    // vector<int> energy(n);

    // for(int i = 0; i<n; i++){
    //     cin>>layers[i];
    // }

    // for(int i = 0; i<n; i++){
    //     cin>>energy[i];
    // }

    // printArr(solution(vector<int> {5, 8, 1}, vector<int> {5, 2, 1}, 10));
    // printArr(solution(vector<int> {5, 3, 1}, vector<int> {5, 2, 1}, 6));
    // printArr(solution(vector<int> {5, 3, 3}, vector<int> {5, 2, 1}, 6));
    // printArr(solution(vector<int> {5, 3, 3}, vector<int> {5, 2, 1}, 3));
    // printArr(solution(vector<int> {5, 3, 3}, vector<int> {5, 0, 1}, 3));
    // printArr(solution(vector<int> {6, 4, 1}, vector<int> {2, 2, 3}, 7));
    printArr(solution(vector<int> {2, 2, 2}, vector<int> {5, 15, 1}, 10));
    // printArr(solution(vector<int> {5, 3, 3}, vector<int> {5, 2, 10}, 15));
    // printArr(solution(vector<int> {5, 3, 3}, vector<int> {15, 2, 1}, 12));
     printArr(solution(vector<int> {2, 2, 5}, vector<int> {2, 3, 1}, 5));

}