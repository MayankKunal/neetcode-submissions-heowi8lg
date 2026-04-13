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
    TreeNode*help(int ps,int pe,vector<int>&preorder,int is,int ie,vector<int>&
    inorder,unordered_map<int,int>&inMap)
    {
        if(ps>pe) return NULL;
        if(is>ie) return NULL;
        TreeNode*root=new TreeNode(preorder[ps]);
        int  idx=inMap[preorder[ps]];
        int leftLen=idx-is;
        root->left=help(ps+1,ps+leftLen,preorder,is,idx-1,inorder,inMap);
        root->right=help(ps+leftLen+1,pe,preorder,idx+1,ie,inorder,inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return help(0,n-1,preorder,0,n-1,inorder,mp);
    }
};
