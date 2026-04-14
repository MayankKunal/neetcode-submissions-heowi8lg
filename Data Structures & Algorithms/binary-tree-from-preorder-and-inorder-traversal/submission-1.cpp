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
    TreeNode* help(int preStart,int preEnd,vector<int>&preorder,int inStart,int inEnd,
    vector<int>&inorder,unordered_map<int,int>&inMap)
    {
        if(preStart>preEnd || inStart>inEnd) return NULL;
        int rootVal=preorder[preStart];
        TreeNode*root=new TreeNode(rootVal);
        int rootIdx=inMap[rootVal];
        int leftRootSize=rootIdx-inStart;
        root->left=help(preStart+1,preStart+leftRootSize,preorder,inStart,rootIdx-1,inorder,inMap);
        root->right=help(preStart+leftRootSize+1,preEnd,preorder,rootIdx+1,inEnd,inorder,inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
         unordered_map<int,int>inMap;
         int n=inorder.size();
         for(int i=0;i<n;i++)
         {
            inMap[inorder[i]]=i;
         }

         return help(0,n-1,preorder,0,n-1,inorder,inMap);
    }
};
