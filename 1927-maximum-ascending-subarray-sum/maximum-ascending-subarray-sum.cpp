class Solution {
public:
    int maxAscendingSum(vector<int>& arr) {
      int n=arr.size();
      int sum=arr[0];
      int ans=arr[0];
      for(int i=1;i<n;i++)
      {
        if(arr[i]>arr[i-1])
        {
          sum+=arr[i];
          ans=max(ans,sum);
        }
        else
        {
            sum=arr[i];
            ans=max(ans,sum);
        }
      } 
      return ans; 
    }
};