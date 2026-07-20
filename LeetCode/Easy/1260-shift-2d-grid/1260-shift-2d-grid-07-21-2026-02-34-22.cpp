class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        
        int m=grid.size();
        int n=grid[0].size();
        int total=m*n;
        int old_index=0,new_index=0;
        vector<vector<int>> newgrid(m,vector<int>(n,0));
        k=k%total;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                old_index=(i*n+j);
                new_index=(old_index-k);

                if(new_index<0) new_index+=total;

                newgrid[i][j]=grid[new_index/n][new_index%n];

            }
        }

        return newgrid;
        
    }
};