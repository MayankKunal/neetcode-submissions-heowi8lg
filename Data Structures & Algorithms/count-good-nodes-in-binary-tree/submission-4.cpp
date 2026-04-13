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
         res=1;
         maxVal=root->val;
        }
    
     res+=help(root->left,maxVal);
     res+=help(root->right,maxVal);
return res;

    }
public:
    int goodNodes(TreeNode* root) {
        
        if(!root) return 0;
        return help(root,root->val);
    }
};
