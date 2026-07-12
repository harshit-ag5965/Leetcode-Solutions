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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int prev, n;

        while(!q.empty()){
            prev = INT_MIN, n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(prev >= curr->val || curr->val % 2 == 0) return false;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right); 

                prev = curr->val;
            }
            
            prev = INT_MAX, n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(prev <= curr->val || curr->val % 2 == 1) return false;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                prev = curr->val;
            }
        }

        return true;
    }
};