class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
       for(int i=1;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==1)
            {
                mat[i][j]+=mat[i-1][j];
            }
        }
       }
       int ans=0;
       for(int i=0;i<n;i++)
       {
    for(int j=0;j<m;j++)
    {   
        int mini=INT_MAX;
        for(int k=j;k<m;k++)
        {
            mini=min(mini,mat[i][k]);
            ans+=mini;
        }
    }
   
       }
        return ans;

    }
};