class Solution {
public:
    bool isThree(int nums) {
        if(nums == 1 || nums == 2) return false;
        
        int n = sqrt(nums);
        if(n * n != nums) return false;

        for(int i = 2; i < n; i++){
            if(n % i == 0) return false;
        }

        return true;
        
    }
};