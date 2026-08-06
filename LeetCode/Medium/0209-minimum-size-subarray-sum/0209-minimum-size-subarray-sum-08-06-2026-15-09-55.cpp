class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen=INT_MAX;
        int sum=0,l=0;

        for(int r=0;r<nums.size();r++)
        {
            sum+=nums[r];

            while(l<=r && sum>=target)
            {
                int len=r-l+1;
                minlen=min(minlen,len);
                sum-=nums[l];
                l++;
            }
        }
        return minlen==INT_MAX?0:minlen;
    }
};