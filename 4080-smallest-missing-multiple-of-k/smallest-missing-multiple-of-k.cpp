class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++)
       {
        mp[nums[i]]++;
       }
       int p=1;
       while(k*p)
       {
        if(mp[k*p]<1)
        {
            return k*p;
        }
        ++p;
       } 
       return k*p;
    }
};