class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
    int n=nums.size();
    
     long long ans=0;
     int i=0;
     int j=0;
     long long s=0;
     while(i<n)
     {
      s+=nums[i];
      while(j<=i && 1ll*(i-j+1)*(s)>=k)
      {
        s-=nums[j];
        j++;
      }
      if(j<=i)
      {
        ans+=i-j+1;
      }
      i++;
     } 
     return ans;
    }
};