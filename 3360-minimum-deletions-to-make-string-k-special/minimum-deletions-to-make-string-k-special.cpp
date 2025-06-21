class Solution {
public:
    int minimumDeletions(string arr, int k) {
      unordered_map<int,int>mp;
      for(int i=0;i<arr.size();i++)
      {
        mp[arr[i]-'a']++;
      } 
      vector<int>ans;
      for(auto itr:mp)
      {
        ans.push_back(itr.second);
      } 
      sort(ans.begin(),ans.end());
      int n=ans.size();
      vector<int>right(n,0);
      vector<int>left(n,0);
      left[0]=ans[0];
      right[n-1]=ans[n-1];
      for(int i=1;i<n;i++)
      {
        left[i]=left[i-1]+ans[i];
      }
       for(int i=n-2;i>=0;i--)
      {
        right[i]=right[i+1]+ans[i];
      }
      int res=INT_MAX;
      for(int i=0;i<n;i++)
      {
        int idx=upper_bound(ans.begin()+i,ans.end(),ans[i]+k)-ans.begin();
        int temp=0;
        if(idx<n)
        {
            temp+=(right[idx]-(n-idx)*(ans[i]+k));
        }
        if(i>0)
        {
            temp+=left[i-1];
        }
        res=min(res,temp);
      }
      if(res==INT_MAX)
      {
        return 0;
      }
      return res;

    }
};