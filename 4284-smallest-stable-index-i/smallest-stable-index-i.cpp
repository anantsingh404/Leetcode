class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       int n=nums.size();
       vector<int>left(n,INT_MIN);
       vector<int>right(n,INT_MAX);
       left[0]=nums[0];
       right[n-1]=nums[n-1];
       for(int i=1;i<n;i++)
       {
         left[i]=max(left[i-1],nums[i]);
       }
       for(int i=n-2;i>=0;i--)
       {
         right[i]=min(right[i+1],nums[i]);
       }//int ans=INT_MAX;
       for(int i=0;i<n;i++)
       {
        if(left[i]-right[i]<=k )
        {
            return i;
        }
       }
       return -1;
    }
};