class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
     long long ans=0;
     int n=nums.size();
     unordered_map<int,int>mp;
     int count=0;
     mp[0]=1;
     for(int i=0;i<n;i++)
     { 
        if(nums[i]%modulo==k)
        {
            ++count;
        }
        ans+=mp[(count-k)%modulo];
        mp[count%modulo]++;

     }  
     return ans; 
    }
};