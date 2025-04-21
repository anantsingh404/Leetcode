class Solution {
public:
    int numberOfArrays(vector<int>& diff, int l, int u) {
        int n=diff.size();
      vector<long long>ans(n+1,0);  
      ans[0]=0;
      for(int i=1;i<=n;i++)
      {
        ans[i]=1ll*diff[i-1]+ans[i-1];
      }
     
      sort(ans.begin(),ans.end());
      
      int count=0;
      for(int i=l;i<=u;i++)
      {
        if(ans[0]+i>=l && ans[0]+i<=u  && ans[n]+i<=u && ans[n]+i>=l)
        {
            ++count;
        }
      }
      return count;
    }
};