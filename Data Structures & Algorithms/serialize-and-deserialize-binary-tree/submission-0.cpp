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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string s="";
        if(!root) return "N";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            if(it==NULL) {
                s+="N,";
            continue;
            }
            else s+=to_string(it->val)+',';
            q.push(it->left);
            q.push(it->right);
        }
        // s.pop_back();
        cout<<s;
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        stringstream ss(data);
        string val;
     getline(ss,val,',');
     if(val=="N") return NULL;
      TreeNode*root=new TreeNode(stoi(val));
      queue<TreeNode*>q;
      q.push(root);
     
      while(getline(ss,val,','))
      {
        auto it=q.front();
        q.pop();
        //leftSubtree
        // string leftVal="";
       
        if(val!="N"){
           
                it->left=new TreeNode(stoi(val));
              q.push(it->left);
            }
        
         //right Subtree
         getline(ss,val,',');
        
        if(val!="N")
            {
                it->right=new TreeNode(stoi(val));
              q.push(it->right);
            }
       
      }
      return root;
    }
};
