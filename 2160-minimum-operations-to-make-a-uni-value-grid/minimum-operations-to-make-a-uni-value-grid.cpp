class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>ans;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans.push_back(grid[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        long long sum=accumulate(ans.begin(),ans.end(),1ll*0);
        
        sum=ans[ans.size()/2];
        int re=ans[0]%x;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]%x!=re)
            {
                return -1;
            }
        }
        int count=0;
        for(int i=0;i<ans.size();i++)
        {
            count+=abs(ans[i]-sum)/x;
        }
        return count;

    }
};