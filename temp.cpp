#include <bits/stdc++.h>
using namespace std;

string RemoveSpaces(string A){

    string B = "";

    for(int i = 0; i<A.size(); i++){
        if(A[i] != ' '){
            B = B + A[i];
        }
    }

    return B;

}

int main(){


    string A = "        ridhai    askss     for    some  s     space      ";

    cout<<RemoveSpaces(A)<<endl;
}