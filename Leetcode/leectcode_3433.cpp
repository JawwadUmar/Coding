#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

class Solution {

private:
    vector<int> getIds(string &s){

        stringstream ss(s);
        string word;
        vector<int> res;

        while (getline(ss, word, ' '))
        {
            int num = stoi(word.substr(2));
            res.push_back(num);
        }

        return res;
    }

    void updateMentions(vector<int>&mentions, vector<int>&ids){
        for(int id: ids){
            mentions[id]++;
        }
    }

    void mentionAll(vector<int> &mentions){
        int n = mentions.size();

        for(int i = 0; i<n; i++){
            mentions[i]++;
        }
    }

    void updateOnlinePeople(vector<int>&mentions, int currentTimeStamp, map<int, int> &offline_times){
        
        int n = mentions.size();
        for(int i =0; i<n; i++){
            if(offline_times.find(i) == offline_times.end()){
                mentions[i]++;
                continue;
            }

            int offlineTime = offline_times[i];
            if (currentTimeStamp >= offlineTime + 60){
                mentions[i]++;
            }
        }
    }

    static bool cmp(vector<string> v1, vector<string> v2){
        int timeStamp1 = stoi(v1[1]);
        int timeStamp2 = stoi(v2[1]);

        return timeStamp1 < timeStamp2;
    }

public:

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), cmp);
        vector<int> mentions(numberOfUsers, 0);
        map<int, int> offline_times;

        for (vector<string> event: events){
            int timeStamp = stoi(event[1]);
            if(event[0] == "MESSAGE"){

                if (event[2] == "ALL"){
                    mentionAll(mentions);
                }

                else if(event[2] == "HERE"){
                    updateOnlinePeople(mentions, timeStamp, offline_times);
                }

                else{
                    vector<int> ids = getIds(event[2]);
                    updateMentions(mentions, ids);
                }
                
            }

            else{
                int id = stoi(event[2]);
                offline_times[id] = timeStamp;
            }
        }

        return mentions;
    }
};