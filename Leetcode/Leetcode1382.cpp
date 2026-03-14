#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    private: 
    void inorderTraversal(TreeNode* root, vector<int>&v){
        if(root == NULL){
            return;
        }

        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
    }

    TreeNode* makeBST(int low, int high, vector<int> &v){
        if(low > high){
            return NULL;
        }

        if(low == high){
            TreeNode* node = new TreeNode(v[low]);
            return node;
        }

        int mid = (high+low)/2;
        TreeNode* node = new TreeNode(v[mid]);
        node->val = v[mid];
        TreeNode* l = makeBST(low, mid-1, v);
        TreeNode* r =makeBST(mid+1, high, v);
        node->left = l;
        node->right = r;

        return node;
    }

   public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorderTraversal(root, v);
        for(int x: v){
            cout<<x<<" ";
        }
        cout<<endl;
        return makeBST(0, v.size()-1, v);
    }
};
