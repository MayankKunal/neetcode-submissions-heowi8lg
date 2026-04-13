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
    void help(TreeNode*root,vector<int>&ans)
    {
        if(!root) return;
       help(root->left,ans);
       ans.push_back(root->val);
       help(root->right,ans);
    }
public:
    bool isValidBST(TreeNode* root) {
        
        vector<int>inorder;
        help(root,inorder);
        for(int i=1;i<inorder.size();i++)
        {
            if(inorder[i]<=inorder[i-1]) return false;
        }
        return true;
    }
};
