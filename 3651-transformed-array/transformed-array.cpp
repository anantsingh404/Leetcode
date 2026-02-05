class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        
      vector<int>res(n,0);  
        for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    res[i]=nums[i];
                }
                else if(nums[i]>0)
                {
                   int y=abs(nums[i])%n;
                    int j=i;
                    while(j<n-1 && y>0)
                        {
                           ++j; 
                            --y;
                        }
                    if(y)
                    {
                        j=0;
                        --y;
                    }
                    while(y>0)
                        {
                            ++j;
                            --y;
                        }
                    res[i]=nums[j];
                }
                else 
                {
                    int y=abs(nums[i])%n;
                    int j=i;
                    while(j>0 && y>0)
                        {
                           --j; 
                            --y;
                        }
                    if(y)
                    {
                        j=n-1;
                        --y;
                    }
                    while(y>0)
                        {
                            --j;
                            --y;
                        }
                    res[i]=nums[j];
                    
                }
            }
        return res;
    }
};