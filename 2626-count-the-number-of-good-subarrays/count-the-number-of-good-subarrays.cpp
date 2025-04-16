class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
     long long ans=1ll*n*(n+1)/2;
     int j=0;
     unordered_map<int,int>mp;
    long long count=0;
     for(int i=0;i<nums.size();i++)  
     {
        count+=mp[nums[i]];
        mp[nums[i]]++;
        
        while(count>=k && j<i)
        {
            count-=(mp[nums[j]]-1);
            --mp[nums[j]];
            ++j;
        }
        ans-=(i-j+1);

     } 
     return ans;
    }
};