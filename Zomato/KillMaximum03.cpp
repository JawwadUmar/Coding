#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}

vector<int> getNumPoints(vector<int> layers, vector<int> energy, long k) {
    vector<int> result(layers.size(), 0);

    // making an array of the sum of layers up to the given index
    vector<long> layersSum(layers.begin(), layers.end());
    for (int i = 1; i < layersSum.size(); ++i)
        layersSum[i] += layersSum[i - 1];

    // making a set of indices with (k-energyUsed < energy[index])
    // initially all are added
    unordered_set<int> notPass;
    for (int i = 0; i < layers.size(); ++i)
        notPass.insert(i);

    // iterating on result array to get no of NEW indices with (k-energyUsed < energy[index])
    for (int i = 0; i < result.size(); ++i) {
        // rechecking all the (indices >= i) which were not counted previously
        for (unordered_set<int>::iterator ind = notPass.begin(); ind != notPass.end();) {
            long energyLoss = layersSum[*ind] - (i > 0 ? layersSum[i - 1] : 0);
            if (*ind >= i && k - energyLoss >= 0 && k - energyLoss >= energy[*ind]) {
                ++result[i];
                ind = notPass.erase(ind);
            } else {
                ++ind;
            }
        }
    }

    // making result sum array since at any index, result = new + previous result - 1
    // -1 is to remove the first value from the previous result if that was
    for (int i = 1; i < result.size(); ++i) {
        result[i] += result[i - 1];
        result[i] -= (k - layers[i - 1] >= 0 && k - layers[i - 1] >= energy[i - 1]) ? 1 : 0;
    }

    return result;
}

int main() {
    // printArr(getNumPoints(vector<int> {5, 8, 1}, vector<int> {5, 2, 1}, 10));
    printArr(getNumPoints(vector<int> {5, 3, 1}, vector<int> {5, 2, 1}, 6));
    // printArr(getNumPoints(vector<int> {5, 3, 3}, vector<int> {5, 2, 1}, 6));
    // printArr(getNumPoints(vector<int> {5, 3, 3}, vector<int> {5, 2, 1}, 3));
    // printArr(getNumPoints(vector<int> {5, 3, 3}, vector<int> {5, 0, 1}, 3));
    // printArr(getNumPoints(vector<int> {6, 4, 1}, vector<int> {2, 2, 3}, 7));
    printArr(getNumPoints(vector<int> {2, 2, 2}, vector<int> {5, 15, 1}, 10));
    printArr(getNumPoints(vector<int> {2, 2, 5}, vector<int> {2, 3, 1}, 5));
    // printArr(getNumPoints(vector<int> {5, 3, 3}, vector<int> {5, 2, 10}, 15));
    // printArr(getNumPoints(vector<int> {5, 3, 3}, vector<int> {15, 2, 1}, 12));
    return 0;
}