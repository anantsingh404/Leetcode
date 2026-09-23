class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       int i=0;
       int j=0;
       long long int sum=0;
       int maxi=-1;
       int n=nums.size();
       long long int s=0;
       for(int i=0;i<n;i++)
       {
        s+=nums[i];
       }
       int tg=s-x;
       for(int i=0,j=0;i<n;i++)
       {
       sum+=nums[i];
       
       while(sum>tg && j<=i)
       {
           sum-=nums[j];
           ++j;
       }
       if(sum==tg)
       {
           maxi=max(maxi,i-j+1);
       }
       }
       if(maxi==-1)
       {
           return -1;
       }
       return n-maxi;

    }
};