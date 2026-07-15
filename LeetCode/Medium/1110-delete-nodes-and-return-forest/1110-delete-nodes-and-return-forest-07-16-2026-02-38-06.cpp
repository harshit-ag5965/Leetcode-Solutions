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
    vector<TreeNode*> res;

    TreeNode* deleteHelper(TreeNode* root,unordered_set<int>& st)
    {
        if(root==NULL) return NULL;

        root->left=deleteHelper(root->left,st);
        root->right=deleteHelper(root->right,st);

        if(st.count(root->val))
        {
            if(root->left!=NULL) res.push_back(root->left);
            if(root->right!=NULL) res.push_back(root->right);
            return NULL;
        }else{
            return root;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_set<int> st;
        for(int n:to_delete) st.insert(n);

        deleteHelper(root, st);

        if(!st.count(root->val)) res.push_back(root);

        return res;
    }
};