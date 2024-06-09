class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
     unordered_map<int,int>mp;
     int count=0;
     int n=nums.size();
     int sum=0;
     mp[0]=1;
     for(int i=0;i<n;i++)
     {
      sum+=nums[i];
      int mod=sum%k;
      if(mod<0)
      {
        mod+=k;
      }
      
        count+=mp[mod];
        mp[mod]++;
      }
     
     return count;  
    }
};