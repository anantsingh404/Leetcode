class Solution {
    void solve(int idx,int dp[],List<List<Integer>>ls,int count,List<Integer>temp)
    {
        if(count==0)
        {
            ls.add(new ArrayList<>(temp));
            return;
        }
        if(idx>=dp.length)
        {
            return;
        }
        
            if(dp[idx]==0)
            {
                temp.add(idx);
                dp[idx]=1;
                solve(idx+1,dp,ls,count-1,temp);
                dp[idx]=0;
                temp.remove(temp.get(temp.size()-1));
            }
            solve(idx+1,dp,ls,count,temp);

        
    }
    public List<List<Integer>> combine(int n, int k) {
      List<List<Integer>>ls=new ArrayList<>();
      ArrayList<Integer>temp=new ArrayList<>();
      int dp[]=new int[n+1];

      for(int i=0;i<=n;i++)
      {
        dp[i]=0;
      }
      solve(1,dp,ls,k,temp); 
      return ls; 
    }
}