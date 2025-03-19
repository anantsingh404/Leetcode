class Solution {
public:
    int minOperations(vector<int>& nums) {
       int sum=accumulate(nums.begin(),nums.end(),0);
       int n=nums.size();
       int z=n-sum;
       if(z==0)
       {
        return 0;
       } 
       
       int ans=INT_MAX;
       int count=0;
       vector<int>num(nums.begin(),nums.end());
       for(int i=0;i<n-2;i++)
       {
        if(num[i]==0)
        {
             
             ++count;
             num[i]^=1;
        num[i+1]^=1;
        num[i+2]^=1;

        }
        
       }
       ans=min(ans,count);
       count=0;
        for(int i=n-1;i>1;i--)
       {
        if(nums[i]==0)
        {
             
             ++count;
             nums[i]^=1;
        nums[i-1]^=1;
        nums[i-2]^=1;

        }
        
       }
       if(num[n-1]==0 || num[n-2]==0)
       {
        return -1;
       }
       ans=min(ans,count);
       return ans;
    }
};