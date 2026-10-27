class Solution {
    public String[] createGrid(int m, int n) {
        String[]arr=new String[m];
        StringBuilder st=new StringBuilder();
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                st.append('.');
            }
            else
            {
                st.append('#');
            }
        }
        for(int i=0;i<m;i++)
        {
          
              if(i==m-1)
              {  StringBuilder x=new StringBuilder();
                for(int j=0;j<n;j++)
                {
                    x.append('.');
                }
                arr[i]= x.toString();
              }
              else
              {
               StringBuilder x=new StringBuilder();
               x=st;
               arr[i]= x.toString();
              }
            
          
        }
        return arr;

    }
}