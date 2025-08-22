class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int leftmin=INT_MAX;
       int leftmax=INT_MIN;
       int topmin=INT_MAX;
       int topmax=INT_MIN;
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {   if(grid[i][j]==1){
            leftmin=min(leftmin,j);
            leftmax=max(leftmax,j);
            topmin=min(topmin,i);
            topmax=max(topmax,i);
        }
        }
       }
       if(leftmin==INT_MAX)
       {
        return 0;
       }
       return (leftmax-leftmin+1)*(topmax-topmin+1);


    }
};