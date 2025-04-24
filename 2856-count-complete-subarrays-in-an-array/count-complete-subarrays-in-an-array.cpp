class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
     int count=0;
        set<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            ans.insert(nums[i]);
        }
        int x=ans.size();
        for(int i=0;i<n;i++)
        {
            set<int>flag;
            for(int j=i;j<n;j++)
            {
                flag.insert(nums[j]);
                if(flag.size()==x)
                {
                    ++count;
                }
            }
        }
        return count;
    }
};