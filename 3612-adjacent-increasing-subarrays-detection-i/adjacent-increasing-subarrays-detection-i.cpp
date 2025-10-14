class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& arr, int k) {
       bool ans=false;
       int n=arr.size();
       int i=0;
       int j=1;
       bool flag=1;
       if(j-i+1>=2*k)
       {
        return true;
       }
       while(j<n) 
       {
        
        if(arr[j]>arr[j-1])
        { // cout<<endl;
          // cout<<i<<endl;
          // cout<<j<<endl; 
            
            if(j-i+1>=2*k || (flag==0 && j-i+1>=k))
            {
                return true;
            }
            j++;
        }
        else if(arr[j]<=arr[j-1])
        {
            if(j-i>=k && flag)
            {   i=j;   
                j++;
                flag=0;
                 cout<<j<<endl; 
            }
            else
            {  // cout<<j<<endl; 
                i=j;
                flag=1;
                j++;
            }
            }
       }
       return false;
    }
};