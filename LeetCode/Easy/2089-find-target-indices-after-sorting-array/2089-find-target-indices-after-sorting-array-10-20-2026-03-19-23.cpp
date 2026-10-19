class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        vector<int> result;
        
        // Step 2: Collect indices matching the target
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};