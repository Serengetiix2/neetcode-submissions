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
    int maxlength = 0;
    int dfs(TreeNode* root, int height){
        if(root == nullptr) return height;
        {
        int newHeight = height + 1;
        int rightdepth = dfs(root->right, newHeight);
        int leftdepth = dfs(root->left, newHeight);
        maxlength = max(maxlength, (rightdepth - newHeight) + (leftdepth - newHeight));
        return max(rightdepth, leftdepth);
        }
        ++height;
        int rightpath = dfs(root->right, height);
        int leftpath = dfs(root->left, height);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) return 0;
        TreeNode* right = root->right;
        TreeNode* left = root->left;
        dfs(root, 0);
        return maxlength;
    }
};