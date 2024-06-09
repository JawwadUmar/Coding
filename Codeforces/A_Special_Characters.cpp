#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;

        if(n%2){
            cout<<"NO"<<endl;
        }

        else{
            cout<<"YES"<<endl;

            string a = "AA";
            string b = "BB";
            int cnt = 0;
            string res = "";

            while (n)
            {
                if(cnt%2){
                    res+=a;
                }

                else{
                    res+=b;
                }

                n-=2;
                cnt++;
            }
            
            cout<<res<<endl;
        }
    }
    
}