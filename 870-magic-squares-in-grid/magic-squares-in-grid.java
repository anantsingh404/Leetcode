class Solution {
    public int numMagicSquaresInside(int[][] grid) {
      int count=0;
      int n=grid.length;
      int m=grid[0].length;
      for(int i=0;i<n-2;i++)
      {
        for(int j=0;j<m-2;j++)
        {   Set<Integer> set = new HashSet<>();
           int[] h = new int[3];
            int[] v = new int[3];

            int d1=0;
            int d2=0;
            Boolean temp=true;
            for(int k=i;k<i+3;k++)
            {
                for(int l=j;l<j+3;l++)
                {
                  if(grid[k][l]<=9 && grid[k][l]>0)
                  {
                    set.add(grid[k][l]);
                  }
                  h[k-i]+=grid[k][l];
                  v[l-j]+=grid[k][l];
                 if (k - i == l - j) {
    d1 += grid[k][l];        // main diagonal
}
if ((k - i) + (l - j) == 2) {
    d2 += grid[k][l];        // secondary diagonal
}
                }
            }
            if(set.size()!=9)
            {
                temp=false;
            }
            if(h[0]!=h[1] || h[1]!=h[2])
            {
                temp=false;
            }
             if(v[0]!=v[1] || v[1]!=v[2])
            {
                temp=false;
            }
            if(d1!=d2)
            {
                temp=false;
            }
            if(temp)
            {
                ++count;
            }
        }
      }
      return count;  
    }
}