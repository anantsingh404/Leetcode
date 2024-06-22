class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
     unordered_map<int,int> mp;
     int count=0;
     int sum=0;
     mp[0]=1;
     for(int i=0;i<nums.size();i++)
     {
        if(nums[i]%2)
        {
            ++sum;
            count+=mp[sum-k];
            mp[sum]++;
        }
        else
        {  count+=mp[sum-k];
            mp[sum]++;
        }
     }
     return count;   
    }
};