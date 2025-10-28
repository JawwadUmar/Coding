#include <bits/stdc++.h>
using namespace std;


// vector<string> processLogs(vector<string> logs, int threshold){

//     map<string, int> mp;

//     for(int i = 0; i<logs.size(); i++){

//         stringstream ss(logs[i]);
//         string word;
//         vector<string> temp;
//         while (getline(ss, word, ' '))
//         {
//             temp.push_back(word);
//         }

//         if(temp[0] == temp[1]){
//             mp[temp[0]]++;
//         }


//         else{

//             mp[temp[0]]++;
//             mp[temp[1]]++;
//         }
        
//     }

//     vector<string> res;

//     for(auto it: mp){
//         if(it.second >= threshold){
//             res.push_back(it.first);
//         }
//     }

//     return res;
// }



int changeX(char c){
    if(c == 'R'){
        return 1;
    }

    if(c == 'L'){
        return -1;
    }

    return 0;
}

int changeY(char c){
    if(c == 'U'){
        return 1;
    }

    if(c == 'D'){
        return -1;
    }

    return 0;
}
int getMaxDelections(string s){
    int delx = 0;
    int dely = 0;

    for(auto it: s){
        delx+= changeX(it);
        dely+= changeY(it);
    }

    int reqSize = abs(delx) + abs(dely);
    int n = s.size();
    return n - reqSize;

}

int main(){

    

}