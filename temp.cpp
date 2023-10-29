#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to generate palindromic numbers with a given length
vector<long long> generatePalindromicNumbers(int length) {
    vector<long long> palindromicNumbers;
    
    if (length % 2 == 1) {
        // Odd length palindromic numbers
        int start = 1;
        int end = 9;
        for (int center = start; center <= end; center++) {
            string left = to_string(center);
            string right = left;
            for (int i = 0; i <= 9; i++) {
                string palindrome = left + to_string(i) + right;
                palindromicNumbers.push_back(stoll(palindrome));
            }
        }
    } else {
        // Even length palindromic numbers
        int start = 1;
        int end = 9;
        for (int i = start; i <= end; i++) {
            string left = to_string(i);
            string right = left;
            palindromicNumbers.push_back(stoll(left + right));
        }
    }
    
    return palindromicNumbers;
}

int main() {
    const long long limit = 1000000000000LL; // 10^12
    vector<long long> palindromicNumbers;
    
    for (int length = 1; ; length++) {
        vector<long long> palindromicLength = generatePalindromicNumbers(length);
        for (long long num : palindromicLength) {
            if (num <= limit) {
                palindromicNumbers.push_back(num);
            } else {
                break;
            }
        }
    }
    
    cout << "Palindromic numbers up to 10^12:" << endl;
    for (long long num : palindromicNumbers) {
        cout << num << " ";
    }
    
    cout << endl;

    return 0;
}
