class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long count=0;for(int i=0;i<n-1;i++)
        {
            int diff1=lower-nums[i];
            int diff2=upper-nums[i];
            int x=lower_bound(nums.begin()+i+1,nums.end(),diff1)-nums.begin();
            int y=upper_bound(nums.begin()+i+1,nums.end(),diff2)-nums.begin();
            --y;
            //cout<<x<<" "<<y<<endl;
            if(y>=x && x>i)
            {
                count+=y-x+1;
            }
        }
        return count;
    }
};