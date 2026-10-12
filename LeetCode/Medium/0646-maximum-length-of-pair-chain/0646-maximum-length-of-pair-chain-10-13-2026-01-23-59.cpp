class Solution {
public:
    int findLongestChain(vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        int lastEndTime=INT_MIN,count=0;
        
        for(auto meeting : meetings)
        {
            int currStart=meeting[0];
            int currEnd=meeting[1];
            
            if(currStart>lastEndTime)
            {
                count++;
                lastEndTime=currEnd;
            }
        }
        
        return count;
    }
};