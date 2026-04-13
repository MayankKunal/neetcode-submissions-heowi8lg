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
    int help(TreeNode*root,int maxVal)
    {
        if(!root) return 0;
        int res=0;
        if(root->val>=maxVal)
        {
        return 1+help(root->left,root->val)+help(root->right,root->val);
        }
    
        return help(root->left,maxVal)+help(root->right,maxVal);


    }
public:
    int goodNodes(TreeNode* root) {
        
        if(!root) return 0;
        return help(root,root->val);
    }
};
