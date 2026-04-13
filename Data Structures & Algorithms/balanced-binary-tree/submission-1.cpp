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
    bool isBalanced(TreeNode* root) {
        
        return help(root).first;
    }
    pair<bool,int>help(TreeNode*root)
    {
           if(!root) return {1,0};

           pair<bool,int>lh=help(root->left);
           pair<bool,int>rh=help(root->right);
              
            bool isBalanced=(lh.first && rh.first && (abs(lh.second-rh.second)<=1));

            return {isBalanced,1+max(lh.second,rh.second)};
    }
};
