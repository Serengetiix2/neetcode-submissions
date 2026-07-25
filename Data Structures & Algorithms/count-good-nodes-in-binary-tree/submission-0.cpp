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
    int dfs(TreeNode* root, int pathMax){
        int nodes = 0;
        if(!root) return 0;
        if(root->val >= pathMax){
            ++nodes;
            pathMax = root->val;
        }
        auto rightNodes = dfs(root->right, pathMax);
        auto leftNode = dfs(root->left, pathMax);
        nodes += (rightNodes + leftNode);
        return nodes;
        
    }
    int goodNodes(TreeNode* root){
       return dfs(root, root->val);
        
    }
};
