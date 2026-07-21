class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid = nums.size()/2;

        int target = nums[mid];
        nums[mid] = 0;

        for(int num: nums){
            if(target == num) return false;
        }

        return true;
    }
};