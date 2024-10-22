class Solution {
public:
   int check(int x,int y)
   {
    int ans=-1;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            if(i<=y)
            {
                ans=max(ans,i);
                break;
            }
           
               
        }
    }
    if(ans>y)
    {
        return -1;
    }
    return ans;
   }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;
       for(int i=n-2;i>=0;i--)
       {    if(nums[i]<=nums[i+1])
           {
            continue;
           }
        int x=check(nums[i],nums[i+1]);
           if(x==-1)
           {
            return -1;
           }

           ++count;
           nums[i]=x;
            
       
       }
       return count; 
    }
};