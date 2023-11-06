#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n,k; cin>>n>>k; 
    vector<int> layers(n), energy(n); 
    for(int i = 0; i < n; i++) cin>>layers[i]; 
    for(int i = 0; i < n; i++) cin>>energy[i]; 
    // two pointers approach 
    // if some position can be reached from position i, we can also reach it from i+1
    // we may reach even further after incrementing left pointer 
    // right pointer points to position which can be reached, it is not necessary to defeat it
    // so have to explicitly check if enemy on right pointer can be defeated
    int left = 0; 
    int right = 0;  
    for(left = 0; left <n; left++)
    {
        if(right != (n+1))
        {
            int required = layers[right] + energy[right]; 
            while(k >= required)
            {
                k-= layers[right];
                right++; 
                if(right == n+1) break;
                required = layers[right] + energy[right]; 
            }
        }
        int cnt = right - left; 
        // checking explicitly if enemy on right pointer can be defeated
        if(right!=n+1)
        {
            if(k >= layers[right]) cnt++; 
        }
        cout<<cnt<<" "; 
        k += layers[left]; 
    }    
}