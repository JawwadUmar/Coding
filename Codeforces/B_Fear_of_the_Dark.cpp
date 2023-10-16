#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
int binaryExponentiation(int x, int p){
    int res = 1;
    while(p){
        if(p%2){
            res = (res * x)%MOD;
        }

        x = (x*x)%MOD;
        p = p/2;
    }
    
    return res;
}

//ctrl shift B for output

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}


void solve(){

    double x, y;
    cin>>x>>y;

    double x1, y1, x2, y2;

    cin>>x1>>y1;
    cin>>x2>>y2;

    //Monocarp to both lartern
    double d1 = sqrt(x1*x1 + y1*y1);
    double d2 = sqrt(x2*x2 + y2*y2);

    //larten to house
    double d3 = sqrt((x-x1)*(x-x1) + (y - y1)*(y-y1));
    double d4 = sqrt((x-x2)*(x-x2) + (y - y2)*(y-y2));

    if(d1 <= d2 && d3<= d4){
        //only 1st larten do the work

        double r11 = d1;
        double r12 = d3;

        cout << fixed << setprecision(10)<<max(r11, r12)<<endl;
        return;
    }

    if(d1 >= d2 && d3 >= d4){
        //only 1st larten do the work

        double r11 = d2;
        double r12 = d4;

        cout << fixed << setprecision(10)<<max(r11, r12)<<endl;
        return;
    }

    //both the circles are needed

    double dist_bw_centre = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

    //if circle 1 is nearer to mono
    if(d1 <= d2){

        double r1 = d1;
        double r2 = d4;

        double r = max(r1, r2);

        if(2*r >= dist_bw_centre){
            cout << fixed << setprecision(10)<<r<<endl;
            return;
        }

        double r3 = dist_bw_centre/2;

        cout << fixed << setprecision(10)<<r3<<endl;
        return;
    }

    //circle 2 is closer to mono

    else{

        double r1 = d2;
        double r2 = d3;

        double r = max(r1, r2);

        if(2*r >= dist_bw_centre){
            cout << fixed << setprecision(10)<<r<<endl;
            return;
        }

        double r3 = dist_bw_centre/2;

        cout << fixed << setprecision(10)<<r3<<endl;
        return;
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}