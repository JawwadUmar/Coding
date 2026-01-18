#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};


class Solution {
public:

    vector<TreeNode*> getDeepestNode(TreeNode* root, map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> res;

        while (!q.empty())
        {
            int n = q.size();
            vector<TreeNode*> level;

            for(int i = 0; i<n; i++){
                TreeNode* parentRoot = q.front();
                level.push_back(parentRoot);
                q.pop();

                if(parentRoot->left){
                    parent[parentRoot->left] = parentRoot;
                    q.push(parentRoot->left);
                }

                if(parentRoot->right){
                    parent[parentRoot->right] = parentRoot;
                    q.push(parentRoot->right);
                }
            }

            res = level;
        }
        
        return res;
    }

    bool allParentsSame(vector<TreeNode*> &deepestNodes, map<TreeNode*, TreeNode*> &parent){
        TreeNode* ultimateParent = parent[deepestNodes[0]];

        for(int i = 1; i<deepestNodes.size(); i++){
            if(parent[deepestNodes[i]] != ultimateParent){
                return false;
            }
        }
        return true;
    }

    void ifNotSameMakeSame(vector<TreeNode*> &deepestNodes,  map<TreeNode*, TreeNode*> &parent){
        bool flag = false;
        for(int i =1; i<deepestNodes.size(); i++){
            if(deepestNodes[i] != deepestNodes[i-1]){
                flag = true;
                break;
            }
        }

        if(flag){
            for(int i = 0; i<deepestNodes.size(); i++){
                deepestNodes[i] = parent[deepestNodes[i]];
            }
        }
    }


    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        map<TreeNode*, TreeNode*> parent;
        vector<TreeNode*> deepestNodes =  getDeepestNode(root, parent);

        if(deepestNodes.size() == 1){
            return deepestNodes[0];
        }

        while (!allParentsSame(deepestNodes, parent))
        {
            for(int i = 0; i<deepestNodes.size(); i++){
                deepestNodes[i] = parent[deepestNodes[i]];
            }
        }

        ifNotSameMakeSame(deepestNodes, parent);

        return deepestNodes[0] == nullptr ? root : deepestNodes[0];
        
    }
};