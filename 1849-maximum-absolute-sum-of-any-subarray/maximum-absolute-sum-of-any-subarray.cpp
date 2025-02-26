class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
     int maxi=0;
     int mini=0;
     int sum=0;
     for(int i=0;i<nums.size();i++)
     {
     sum+=nums[i];
     maxi=max(maxi,sum);
     if(sum<0)
     {
        sum=0;
     }
     }  
     sum=0;
      for(int i=0;i<nums.size();i++)
     {
sum+=nums[i];
     mini=min(mini,sum);
     if(sum>0)
     {
        sum=0;
     }
     } 
     return max(abs(maxi),abs(mini)); 

    }
};