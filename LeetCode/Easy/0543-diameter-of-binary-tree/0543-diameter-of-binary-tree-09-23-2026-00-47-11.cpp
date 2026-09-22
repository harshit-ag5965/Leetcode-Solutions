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

    int diameter=0;

    int height(TreeNode* root)
    {
        if(root==NULL) return -1;
        int leftlength=height(root->left);
        int rightlength=height(root->right);

        diameter=max(diameter,leftlength+rightlength+2);
        return 1+max(leftlength,rightlength);
    }


    int diameterOfBinaryTree(TreeNode* root) {

        diameter = 0;
        height(root);
        return diameter;
    }
};