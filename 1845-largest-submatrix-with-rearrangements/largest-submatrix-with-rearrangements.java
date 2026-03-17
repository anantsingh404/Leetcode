class Solution {
    public int largestSubmatrix(int[][] matrix) {
      int ans=0;
      int n=matrix.length;
      int m=matrix[0].length;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(i-1>=0 && matrix[i-1][j]>=1 && matrix[i][j]==1)
            {
matrix[i][j]+=matrix[i-1][j];
            }
        }
        ArrayList<Integer>ls=new ArrayList<>();
        for(int j=0;j<m;j++)
        {
            ls.add(matrix[i][j]);
        }
        Collections.sort(ls);
        for(int j=0;j<m;j++)
        {   
            ans=Math.max((ls.get(j)*(m-j)),ans);
            System.out.println(ans);
        }
      }
return ans;
    }
    
}