class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
       int count=0;
       int n=grid.size();
       int m=grid[0].size();
       int i=0;
       int j=0;
       while(j<m)
       {
        int k=1;
        while(k<n)
        {
            if(grid[k][j]<=grid[k-1][j])
            {
                count+=abs(grid[k][j]-grid[k-1][j])+1;
                
                grid[k][j]=grid[k][j]+abs(grid[k][j]-grid[k-1][j])+1;

            }
            k++;
        }
        j++;
       }
       return count;


    }
};