class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int totalSum = 0;
        
        for (int i = 0; i < rows; ++i) {
            sort(grid[i].begin(), grid[i].end());
        }
        
        for (int c = cols - 1; c >= 0; --c) {
            int currentMax = 0;
            
            for (int r = 0; r < rows; ++r) {
                currentMax = max(currentMax, grid[r][c]);
            }
            
            totalSum += currentMax;
        }
        
        return totalSum;
    }
};