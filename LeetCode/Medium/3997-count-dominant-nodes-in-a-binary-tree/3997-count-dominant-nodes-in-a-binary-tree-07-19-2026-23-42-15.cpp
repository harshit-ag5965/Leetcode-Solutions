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
    int res = 0;
    int helper(TreeNode* node){
        if(node == nullptr) return 0;
        int left = helper(node->left);
        int right = helper(node->right);

        int maxVal = max(left, right);

        if(node->val >= maxVal){
            res++;
            return node->val;
        }else{
            return maxVal;
        }
    }
    int countDominantNodes(TreeNode* root) {
        helper(root);
        return res;
    }
};