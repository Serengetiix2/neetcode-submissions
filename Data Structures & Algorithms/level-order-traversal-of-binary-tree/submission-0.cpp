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
    vector<vector<int>> result;
    void trav(TreeNode* root, int level){
        vector<int> traversal;
        if(!root) return;
        if(root->left != nullptr){
            traversal.push_back({root->left->val});
        }
        if(root->right != nullptr){
            traversal.push_back({root->right->val});
        }
        if(!traversal.empty()){
            if(result.size() >= level +1){
                for(auto nums : traversal){
                    result[level].push_back(nums);
                }
            }else{
                result.push_back(traversal);
            }
            
        }
        ++level;
        trav(root->left,level);
        trav(root->right,level);
        
        
    }

    vector<vector<int>> levelOrder(TreeNode* root){
        if(!root) return result;
        result.push_back({root->val});
        vector<int> start;
        trav(root, 1);
        return result;
    }
};
