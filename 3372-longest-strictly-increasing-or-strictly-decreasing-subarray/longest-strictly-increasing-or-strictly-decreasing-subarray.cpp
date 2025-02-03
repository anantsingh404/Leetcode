class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int n=arr.size();
        int res=1;
        for(int i=0;i<n;i++)
        {   bool ans=false;
            for(int j=i+1;j<n;j++)
            {
               if(arr[j]>=arr[j-1])
               {
                ans=true;
               }
               if(ans==false)
            {
                res=max(res,j-i+1);
            }
            }
            
            ans=false;
            for(int j=i+1;j<n;j++)
            {
               if(arr[j]<=arr[j-1])
               {
                ans=true;
               }
                if(ans==false)
            {
                res=max(res,j-i+1);
            }
            }
           
        }
        return res;
    }
};