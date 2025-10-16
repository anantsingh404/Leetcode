class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
      sort(nums.begin(),nums.end());
      int n=nums.size();
      for(int i=0;i<n;i++)
      {
        if(nums[i]<0)
        {
            int p=abs(nums[i])/value;
            if(abs(nums[i])%value)
            {
                nums[i]+=value;
            }
            nums[i]=nums[i]+p*value;
        }
        else
        {
            int p=abs(nums[i])/value;
           
            nums[i]=nums[i]-p*value;
        }
      }
      sort(nums.begin(),nums.end());
      unordered_map<int,int>mp;
      for(int i=0;i<n;i++)
      {
        mp[nums[i]]++;
      } 
      for(int i=0;i<=n;i++){
        if(mp[i]>0)
        {
            --mp[i];
        }
        else
        {
            int x=i%value;
            if(mp[x]>0){
                --mp[x];
            }
            else
            {
                return i;
            }
        }
      } return 0;
    }
};