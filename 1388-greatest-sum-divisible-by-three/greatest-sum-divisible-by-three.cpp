class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     int sum=accumulate(nums.begin(),nums.end(),0);
     if(sum%3==0)
     {
        return sum;
     } 
     if(sum%3==1)
     {
       int ans1=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%3==1)
            {
                ans1=min(ans1,nums[i]);
            }
        }
        int c=0;
        int ans2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%3==2 && c<2)
            {++c;
            ans2+=nums[i];
            }
        }
        if(c==2)
        {
            ans1=min(ans1,ans2);
        }
        if(ans1==INT_MAX)
        {
            return 0;
        }else
        {
            return sum-ans1;
        }
     
     }
     if(sum%3==2)
     {
        int ans1=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%3==2)
            {
                ans1=min(ans1,nums[i]);
            }
        }
        int c=0;
        int ans2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%3==1 && c<2)
            {++c;
            ans2+=nums[i];}
        }
    
        if(c==2)
        {
            ans1=min(ans1,ans2);
        }
        if(ans1==INT_MAX)
        {
            return 0;
        }else
        {
            return sum-ans1;
        }
     
     }
     return 0;  
    }
};