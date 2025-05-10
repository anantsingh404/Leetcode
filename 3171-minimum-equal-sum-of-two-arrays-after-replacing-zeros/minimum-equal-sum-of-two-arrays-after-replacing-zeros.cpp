class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
       long long sum1=accumulate(nums1.begin(),nums1.end(),1ll*0); 
        long long sum2=accumulate(nums2.begin(),nums2.end(),1ll*0); 
        int count1 =count(nums1.begin(),nums1.end(),0);
          int count2 =count(nums2.begin(),nums2.end(),0);
          if(sum1==sum2 && count1==count2)
          {
            return sum1+count1;
          }
          if(count1 && count2  && (sum1==sum2))
          {
            if(count1==count2)
            {
                return sum1+count1;
            }
            else
            {
                return max(sum1+count1,sum2+count2);
            }
          }
          if(sum1==sum2)
          {
            if(count1 && count2)
            {
                return max(sum1+count1,sum2+count2); 
            }
            if(count1 || count2)
            {
                return -1;
            }
          }
          if(sum1!=sum2)
          {
            if(count1 && count2)
            {
                return max(sum1+count1,sum2+count2); 
            }
            if(count1)
            {
             if(sum2>=count1+sum1)
             {
                return sum2;
             }
             else
             {
                return -1;
             }
            }
             if(count2)
            {
              if(sum1>=sum2+count2)
              {
                return sum1;
              }  
              else
              {
                return -1;
              }
            }
             return -1;

          }
          return 0;
    }
};