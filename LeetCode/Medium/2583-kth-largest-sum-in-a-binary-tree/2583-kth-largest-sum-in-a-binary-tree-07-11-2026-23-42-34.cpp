class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int totalLevels = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            long long currentLevelSum = 0;
            totalLevels++;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                currentLevelSum += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            minHeap.push(currentLevelSum);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        if (totalLevels < k) {
            return -1;
        }
        
        return minHeap.top();
    }
};