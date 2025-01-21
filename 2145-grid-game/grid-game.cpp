class Solution {
public:
int n;

    long long gridGame(vector<vector<int>>& grid) {
        n=grid[0].size();
    
    long long s1=accumulate(grid[0].begin(),grid[0].end(),1ll*0);
    long long s2=accumulate(grid[1].begin(),grid[1].end(),1ll*0);
    
    vector<long long>left(n,0);
    vector<long long>right(n,0);
    left[0]=grid[0][0];
    for(int i=1;i<n;i++)
    {

         left[i]=left[i-1]+ grid[0][i];
    }
    right[n-1]=grid[1][n-1];
    for(int i=n-2;i>=0;i--)
    {

         right[i]=right[i+1]+grid[1][i];
    }
   
   
    long long ans=1e18;
    for(int i=0;i<n;i++)
    {
       long long a=s1-left[i];
       long long b=s2-right[i];
       long long flag=max(a,b);
       ans=min(ans,flag);
    }
    return ans;
    



    }
};