#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "AbCdEfg";

    //converting to capital

    for(int i = 0; i<s.size(); i++){
        
        if(s[i]<98){
            continue;
        }

        s[i] = s[i] - 32;
    }

    cout<<s<<endl;
}