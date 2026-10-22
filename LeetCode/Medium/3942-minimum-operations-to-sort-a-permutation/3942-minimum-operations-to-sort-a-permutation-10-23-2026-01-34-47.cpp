class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        bool inc = true, desc = true;
        int p = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) p = i;

            int next = nums[(i + 1) % n];

            // Check cyclically increasing order
            if (next != (nums[i] + 1) % n) {
                inc = false;
            }

            // Check cyclically decreasing order
            if (next != (nums[i] - 1 + n) % n) {
                desc = false;
            }
        }

        if (inc)
            return min(p, n - p + 2);

        if (desc)
            return min(n - p, p + 2);

        return -1;
    }
};