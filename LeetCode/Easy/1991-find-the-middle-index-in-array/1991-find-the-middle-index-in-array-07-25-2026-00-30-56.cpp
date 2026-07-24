class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int ans=0,n=nums.size();
        vector<int> v(n+1,0);
        for(int i=0; i<n; i++){
            ans+=nums[i];
            v[i+1]=ans;
        }
        for(int i=0; i<n; i++){
            if(v[i] == v[n] - v[i+1]){
                return i;
            }
        }
        return -1;
    }
};