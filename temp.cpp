#include <bits/stdc++.h>
using namespace std;

int bandMemberAtk(int totalMembers, vector<vector<int>> swapMembers, int posMember) {
    map<int, int> mp;
    mp[posMember] = posMember;
    for(vector<int> v: swapMembers){
        int a = v[0];
        int b = v[1];
        if(mp.find(a) == mp.end()){
            mp[a] = a;
        }
        if(mp.find(b) == mp.end()){
            mp[b] = b;
        }
    }
    
    for(vector<int> v: swapMembers){
        int a = v[0];
        int b = v[1];
        int temp = mp[a];
        mp[a] = b;
        mp[b] = temp;
    }

    return mp[posMember];
}


// int checkTree(vector<vector<int>> matInput) {
//     int n = matInput.size();
//     int edgeCount = 0;

//     // Count edges
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (matInput[i][j] == 1) {
//                 if (i==j){
//                     return 0;
//                 }
//                 edgeCount++;
//             }
//         }
//     }

//     // Since undirected graph, divide by 2
//     edgeCount /= 2;

//     // Tree condition
//     if (edgeCount == n - 1) {
//         return 1;
//     }

//     return 0;
// }

int main(){
    int n;
    n = 10;
    vector<vector<int>> swapMembers = {{1,5}, {6, 10}};
    cout<<bandMemberAtk(10, swapMembers, 1);
}