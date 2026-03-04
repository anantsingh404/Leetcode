class Solution {
    public int numSpecial(int[][] mat) {
        int n=mat.length;
        int m=mat[0].length;
     int count=0;
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==1)
            {   boolean ans=true;
                for(int k=0;k<n;k++)
                {
                    if(k==i)
                    {
                        continue;
                    }
                    if(mat[k][j]==1)
                    {
                        ans=false;
                    }
                }
                 for(int k=0;k<m;k++)
                {
                    if(k==j)
                    {
                        continue;
                    }
                    if(mat[i][k]==1)
                    {
                        ans=false;
                    }
                }
                if(ans==true)
                {
                    ++count;
                }
            }
        }
     } 
     return count;
    }
}