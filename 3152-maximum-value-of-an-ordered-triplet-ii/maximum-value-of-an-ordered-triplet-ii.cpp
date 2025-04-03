class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
         stack<int>st;
        long long ans=0;
        int n=nums.size();
         vector<int>greater(n,0);
        greater[n-1]=nums[n-1];
        int maxi=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
           greater[i]=max(nums[i],maxi); 
            maxi=greater[i];
        }
        for(int i=0;i<n-1;i++)
        {
            if(st.empty())
             {
            st.push(nums[i]);
            }
            if(st.top()<nums[i])
            {
                st.push(nums[i]);
            }
            else if(nums[i]<st.top())
            {
                long long flag=(long long)(st.top()-nums[i])*greater[i+1];
                ans=max(ans,flag);
            }
           
            
        }
      
        return ans;
    }
};