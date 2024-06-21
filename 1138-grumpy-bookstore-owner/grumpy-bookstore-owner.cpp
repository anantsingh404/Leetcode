class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grumpy, int minu) {
      unordered_map<int,int>mp;
      unordered_map<int,int>mp1;
      int n=grumpy.size();
      int sum=0;
      int flag=0;
      for(int i=0;i<grumpy.size();i++)
      {
        if(grumpy[i]==0)
      {
        flag+=cust[i];
      }
      mp1[i]=flag;
      
        sum+=cust[i];
        mp[i]=sum;
      } 
      int ans=0;
      if(minu>=grumpy.size())
      {
        return mp[n-1];
      }
      for(int i=minu-1;i<n;i++)
      {
       int flag=mp[i]-mp[i-minu]+mp1[n-1]-mp1[i]+mp1[i-minu];
       ans=max(ans,flag);
      } 
      return ans;
    }
};