class Solution {
public:
    int countValidSelections(vector<int>& nums) {
      int sum=0;
       int n=nums.size();
      vector<int>left(n,0);
      vector<int>right(n,0);
      left[0]=nums[0];
     
      right[n-1]=nums[n-1];
      for(int i=1;i<n;i++){
        left[i]=nums[i]+left[i-1];
      }
      for(int i=n-2;i>=0;i--)
      {
        right[i]=nums[i]+right[i+1];
      } 
      for(int i=0;i<n;i++)
      { 
        if(nums[i]!=0)
         {
        continue;
         } 
         if(abs(left[i]-right[i])==0)
        {
            sum+=2;
        }
        if(abs(left[i]-right[i])==1)
        {
            ++sum;
        }
      } 
      
      return sum;
    }
};