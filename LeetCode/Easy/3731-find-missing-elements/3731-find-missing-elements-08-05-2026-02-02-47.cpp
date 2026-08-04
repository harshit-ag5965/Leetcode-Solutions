class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = 100; 
        int mx = 0;   

        unordered_set<int> seen;
        
        for (int num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
            seen.insert(num);
        }

        vector<int> ans;
        for (int i = mn + 1; i < mx; i++) {
            if (!seen.count(i)) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};