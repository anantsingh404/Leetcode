class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            if(nums[i]!=0)
            {
                i++;
                continue;
            }
            else
            {
                int j=i;
                while(j<n && nums[j]==0)
                {
                    ++j;
                }
                sum+=(1ll*(j-i)*(j-i+1))/2;
                i=j;
            }
        }
        return sum;

    }
};