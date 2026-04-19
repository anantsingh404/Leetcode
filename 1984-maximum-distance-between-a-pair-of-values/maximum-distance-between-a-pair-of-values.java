class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
      int ans=0;
      int i=0;
      int j=0;
      int n=nums1.length;
      int m=nums2.length;  
      while(i<n && j<m)
      { 
        if(j<i)
        {
        j++;
        continue;
       }
        else if(nums1[i]<=nums2[j])
        {
            ans=Math.max(ans,j-i);
            j++;
        }
        else if(nums1[i]>nums2[j])
        {
            i++;
        }
        
      }
      return ans;
    }
}