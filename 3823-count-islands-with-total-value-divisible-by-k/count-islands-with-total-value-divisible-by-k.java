class Solution {
    int n,m;
    int arr[]={-1,1,0,0};
    int brr[]={0,0,-1,1};
    long solve(int i,int j,int [][]grid)
    {
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==0)
        {
            return 0;
        }
        long sum=grid[i][j];
        grid[i][j]=0;
        for(int k=0;k<4;k++)
        {
            int x=i+arr[k];
            int y=j+brr[k];
            sum+=solve(x,y,grid);
        }
     return sum;

    }
    public int countIslands(int[][] grid, int k) {
     int count=0;
     n=grid.length;
     m=grid[0].length;
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {       if(grid[i][j]>0){
                long sum=solve(i,j,grid);
                System.out.println(sum);
                if(sum%k==0)
                {
                    ++count;
                }
        }
        }
     } 
     return count;  
    }
}