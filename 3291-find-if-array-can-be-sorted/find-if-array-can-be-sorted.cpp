class Solution {
public:
    void insert(vector<int>&arr,vector<int>&setbits ,int i)
    {       int j=i;
           
            while(j>0 && arr[j]<arr[j-1] && setbits[j]==setbits[j-1])
            {   int x=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=x;
                j--;
            }
            
    }
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>setbits(n,0);
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums[j]&(1<<i))
                {
                    ++setbits[j];
                }
            }
        }
         for(int i=0;i<n;i++)
        {   for(int j=i+1;j<n;j++){
            if(nums[i]>nums[j] && setbits[i]!=setbits[j])
            {
                return false;
            }
        }
            
        }
        return true;
    }
};