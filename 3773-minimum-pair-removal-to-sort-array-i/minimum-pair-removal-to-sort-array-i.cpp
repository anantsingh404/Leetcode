class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
       int count=0;
       
        while(nums.size()>1)
            
            {   int n=nums.size();
                bool temp=true;
                for(int i=0;i<n-1;i++)
                    {
                        if(nums[i]>nums[i+1])
                        {
                            temp=false;
                            break;
                        }
                    }
             if(temp)
             {
                 return count;
             }
                int t=INT_MAX;
                   int i=0;
                  while(i<n-1)
                      {
                          t=min(t,nums[i]+nums[i+1]);
                          i++;
                          
                      }
                    i=0;
             vector<int>ans;
             bool flag=true;
             while(i<n)
                 {
                     if(i<n-1 && nums[i]+nums[i+1]==t && flag)
                     {
                         ans.push_back(nums[i]+nums[i+1]);
                         i+=2;
                         flag=false;
                     }
                     else
                     {
                         ans.push_back(nums[i]);
                         i++;
                     }
                 }
             ++count;
             nums=ans;
            }
        return count;
        
    }
};