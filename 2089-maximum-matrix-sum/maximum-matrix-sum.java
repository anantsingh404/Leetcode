class Solution {
    public long maxMatrixSum(int[][] mat) {
     int count=0;
     long sum=0;
     long mini=1000000000;
     int n=mat.length;
     int m=mat[0].length;
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            sum+=Math.abs(mat[i][j]);
            if(mat[i][j]<0)
            {
                ++count;
            }
            mini=Math.min(mini,Math.abs(mat[i][j]));
        }
     }
     if(count%2==0)
     {
        return sum;
     }
     if(count>0)
     {
        return sum-2*mini;
     }
     return sum;

    }
}