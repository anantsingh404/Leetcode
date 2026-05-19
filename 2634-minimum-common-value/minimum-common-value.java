class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
      int i=0;
      int j=0;
      int n=nums1.length;
      int m=nums2.length;
      while(i<n && j<m)
      {
        if(nums1[i]<nums2[j])
        {
            i++;
            continue;
        }
        if(nums1[i]>nums2[j])
        {
            j++;
            continue;
        }
        return nums1[i];
      }
      return -1;
        
    }
}