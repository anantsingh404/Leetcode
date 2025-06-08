class Solution {
public:
void solve(int i,int n,vector<int>&ans)
{
    if(i<=n)
    {
        ans.push_back(i);
        for(int j=0;j<=9;j++)
        {
            if(i*10+j<=n)
            {
                solve(i*10+j,n,ans);
            }
        }
    }
}
    vector<int> lexicalOrder(int n) {
      vector<int>ans;
      for(int i=1;i<=9;i++) 
      {
        solve(i,n,ans);
      } 
      return ans;
    }
};