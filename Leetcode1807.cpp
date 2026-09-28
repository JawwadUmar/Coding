#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> knowledgeMap;
        for(vector<string> pair: knowledge) {
            knowledgeMap[pair[0]] = pair[1];
        }

        map<int, string> replaceMap;

        int n = s.size();
        bool openBracket = false;
        string replace;
        vector<int> startIndexes;
        vector<int> endIndexes;
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                openBracket = true;
                startIndexes.push_back(i);
                
            }
            else if(s[i] == ')'){
                openBracket = false;
                endIndexes.push_back(i);
                int idx = startIndexes.back();
                if(knowledgeMap.find(replace) != knowledgeMap.end()){
                    replaceMap[idx] = knowledgeMap[replace];
                }
                else{
                    replaceMap[idx] = "?";
                }
                
                replace.clear();
            }

            else if(openBracket == true){
                replace.push_back(s[i]);
            }
        }

        // for(auto it: replaceMap){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        string result;
        int i = 0;
        while (i<s.size())
        {
            if(replaceMap.find(i) == replaceMap.end()){
                result.push_back(s[i]);
                i++;
                continue;
            }
            
            result+= replaceMap[i];
            int toAdd = -1;

            for(int stidx = 0; stidx<startIndexes.size(); stidx++){
                if(startIndexes[stidx] == i){
                    toAdd = endIndexes[stidx];
                    break;
                }
            }

            i = toAdd + 1;
            
        }
        
    }
};