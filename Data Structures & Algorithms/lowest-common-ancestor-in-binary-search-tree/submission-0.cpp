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
    TreeNode*help(TreeNode*root,TreeNode*p,TreeNode*q)
    {
        if(!root || root==p || root==q) return root;
          TreeNode*leftHand=help(root->left,p,q);
        TreeNode*rightHand=help(root->right,p,q);
        if(!leftHand&& !rightHand) return NULL;
         if(!leftHand) return rightHand;
         if(!rightHand) return leftHand;
         return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        

    
        return help(root,p,q);

    }
};
