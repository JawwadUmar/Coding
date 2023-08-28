#include <bits/stdc++.h>
using namespace std;

string f(string s, int k, int flag){


    int n= s.size();
	k = k%n;

    if(!flag){
        k = n-k;
    }

	reverse(s.begin(), s.begin()+n-k);
	reverse(s.begin()+n-k, s.end());

	reverse(s.begin(), s.end());

	return s;

	
}

int main(){
	string s;
    cin>>s;

    int flag;
    cin>>flag;

    int k;
    cin>>k;

    cout<<f(s,k,flag)<<endl;


	return 0;


}