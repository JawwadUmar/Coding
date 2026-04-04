#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // string decodeCiphertext(string encodedText, int rows) {
    //     int textLength = encodedText.size();
    //     int cols = textLength/rows;
    //     vector<vector<char>> mat(rows, vector<char> (cols, ' '));

    //     int idx = 0;
    //     for(int i = 0; i<rows; i++){
    //         for(int j = 0; j<cols; j++){
    //             mat[i][j] = encodedText[idx];
    //             idx++;
    //         }
    //     }

    //     string originialText = "";
    //      for(int c = 0; c<cols; c++){
    //         int stRow = 0;
    //         int stCol = c;
    //         while (stRow < rows && stCol < cols)
    //         {   
    //             originialText.push_back(mat[stRow][stCol]);
    //             stRow++;
    //             stCol++;
    //         }
            
    // }


    // //Remove Trailing Space
    // int idx = -1;
    // for(int i = originialText.size(); i>=0; i--){
    //     if(originialText[i] != ' '){
    //         idx = i;
    //         break;
    //     }
    // }

    // return originialText.substr(0, idx+1);
    // }


    string decodeCiphertext(string encodedText, int rows) {
        int textLength = encodedText.size();
        int cols = textLength/rows;

        string originalText = "";

        for(int c = 0; c<cols; c++){
            for(int j = c; j<encodedText.size(); j+= (cols+1)){
                originalText.push_back(encodedText[j]);
            }
        }
        int idx = -1;
        for(int i = originalText.size()-1; i>=0; i--){
        if(originalText[i] != ' '){
            idx = i;
            break;
        }
    }

    return originalText.substr(0, idx+1);
    }

   
};