/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> travs;
    void trav(TreeNode* root){
        if(!root){
            return;
        } 
        trav(root->left);
        travs.push_back(root->val);
        trav(root->right);
    }
    bool isValidBST(TreeNode* root){
       trav(root);
       for(int i = 0; i < travs.size() - 1; ++i){
        if (travs[i] >= travs[i + 1]) return false;
       }
       return true;
    }
};
