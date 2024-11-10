class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
          int n=nums.size();
        int arr[32]={0};
         int i=0;
        int j=0;
        int flag=0;
        int ans=INT_MAX;
        while(j<n)
        {
            for(int l=0;l<32;l++)
            {
                if(nums[j]&(1<<l))
                {
                    if(arr[l]==0)
                    {
                        flag=flag|(1<<l);
                    }
                    arr[l]++;
                }
                
            }
            while(i<=j && flag>=k)
            {
                ans=min(ans,j-i+1);
                for(int k=0;k<32;k++)
                {
                   if(nums[i]&(1<<k))
                   {
                       arr[k]--;
                       if(arr[k]==0)
                       {
                           flag=flag^(1<<k);
                       }
                   }
                }
                i++;
            }
            j++;
            
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
        
    }
};