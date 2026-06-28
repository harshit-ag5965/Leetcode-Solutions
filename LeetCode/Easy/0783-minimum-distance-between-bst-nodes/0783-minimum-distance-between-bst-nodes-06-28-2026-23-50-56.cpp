class Solution {
private:
    int min_diff = INT_MAX;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;

        // 1. Traverse left subtree
        inorder(node->left);

        // 2. Process current node
        if (prev != nullptr) {
            min_diff = min(min_diff, node->val - prev->val);
        }
        prev = node; // Update previous node to the current one

        // 3. Traverse right subtree
        inorder(node->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        min_diff = INT_MAX;
        prev = nullptr;
        inorder(root);
        return min_diff;
    }
};