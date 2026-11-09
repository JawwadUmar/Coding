#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        map<int, int> freeTime;
        int totalRequests = arrival.size();
        set<int> freeServers;
        vector<int> totalLoads(k);
        priority_queue<P, vector<P>, greater<P>> pq;

        for(int i = 0; i<k; i++){freeServers.insert(i);}
        for(int i = 0; i<totalRequests; i++){

            int arrivalTime = arrival[i];

            while (!pq.empty())
            {
                P ptop = pq.top();
                int serverGettingFreeAt = ptop.first;
                int server = ptop.second;

                if(serverGettingFreeAt <= arrivalTime){
                    pq.pop();
                    freeTime.erase(server);
                    freeServers.insert(server);
                }
                else{
                    break;
                }
                
            }
            

            // for(int server = 0; server<k; server++){
            //     if(freeTime.find(server) != freeTime.end() && freeTime[server] <= arrivalTime){
            //         freeTime.erase(server);
            //         freeServers.insert(server);
            //     }
            // }

            if(freeTime.size() == k){
                //all servers are busy
                continue;
            }

            int serverNo = i%k;

            if(freeTime.find(serverNo) == freeTime.end()){
                freeTime[serverNo] = arrivalTime + load[i];
                freeServers.erase(serverNo);
                totalLoads[serverNo]+=1;
                pq.push(make_pair(arrivalTime + load[i], serverNo));
                continue;
            }

            int freeServer = -1;

            auto it = freeServers.upper_bound(serverNo);
            if(it != freeServers.end()){
                freeServer = *it;
                freeServers.erase(freeServer);
            }
            else{
                auto it2 = freeServers.lower_bound(0);
                freeServer = *it2;
                freeServers.erase(freeServer);
            }

            freeTime[freeServer] = arrivalTime + load[i];
            totalLoads[freeServer]+= 1;
            pq.push(make_pair(arrivalTime + load[i], freeServer));
        }

        int mx = 0;
        for(int x: totalLoads){
            mx = max(x, mx);
        }
        
        vector<int> res;
        for(int i = 0; i<k; i++){
            if(totalLoads[i] == mx){
                res.push_back(i);
            }
        }

        return res;   
    }
};