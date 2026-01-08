class Solution {
    int n,m;
    public int solve(Integer i,Integer j,ArrayList<ArrayList<Integer> > dp,int[] nums1, int[] nums2)
    {
        if(i>=n || j>=m)
        {
            return 0;
        }
        if(dp.get(i).get(j)!=-100000000)
        {
            return dp.get(i).get(j);
        }
        int ans=-100000000;
        ans=Math.max(ans,nums1[i]*nums2[j]+solve(i+1,j+1,dp,nums1,nums2));
         ans=Math.max(ans,solve(i+1,j,dp,nums1,nums2));
          ans=Math.max(ans,solve(i,j+1,dp,nums1,nums2));
          dp.get(i).set(j,ans);
          return dp.get(i).get(j);
        
    }
    public int maxDotProduct(int[] nums1, int[] nums2) {
       n=nums1.length;
        m=nums2.length;
        int maxi=-1000000000;
       
          for(int i=0;i<n;i++)
          {
            for(int j=0;j<m;j++)
            {
                maxi=Math.max(maxi,nums1[i]*nums2[j]);
            }
          }

         ArrayList<ArrayList<Integer> > dp
            = new ArrayList<ArrayList<Integer> >();
            for (int i = 0; i < n; i++) {
    ArrayList<Integer> row = new ArrayList<>();
        for (int j = 0; j < m; j++) {
        row.add(-100000000);
       }
      dp.add(row);
    }
Integer temp=solve(0,0,dp,nums1,nums2);
if(temp==0)
{
    return maxi;
}
return temp;



    }
}