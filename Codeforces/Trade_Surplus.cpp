#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--)
    {
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    int imp = b+d;
    int exp = a+c;

    if(imp > exp){
        cout<<"YES"<<endl;
    }

    else{
        cout<<"NO"<<endl;
    }

    }

    return 0;
}