#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b, c;
    cin>>a>>b>>c;

    string temp = a+b;

    sort(temp.begin(), temp.end());
    sort(c.begin(), c.end());

    if(temp == c){
        cout<<"YES"<<endl;
    }

    else{
        cout<<"NO"<<endl;
    }

    return 0;

}