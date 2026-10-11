#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<long long, int> seen; // value -> index
        for (int i = 0; i < (int)nums.size(); i++) {
            long long need = (long long)target - nums[i]; // can reach 2e9, so use long long
            auto it = seen.find(need);
            if (it != seen.end()) {
                return {it->second, i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};