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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            TreeNode*curr=it.first;
            int val=it.second;
             mp[val]=curr->val;
             if(curr->left)
             {
                q.push({curr->left,val+1});
             }
             if(curr->right)
             {
                q.push({curr->right,val+1});
             }

        }
        vector<int>ans;
        for(auto &x:mp)
        {
            ans.push_back(x.second);
        }
        return ans;

    }
};
