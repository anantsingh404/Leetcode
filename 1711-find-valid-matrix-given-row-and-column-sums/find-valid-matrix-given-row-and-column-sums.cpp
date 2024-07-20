class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int n=row.size();
        int m=col.size();
     vector<vector<int>>dp(n,vector<int>(m,0)); 
     //dp[0][0]=min(row[0],col[0]);
    
     for(int i=0;i<n;i++)
     { 
        for(int j=0;j<m;j++)
        {
            int x=col[j];
            int y=row[i];
            if(x<=y)
            {
                dp[i][j]=x;
                row[i]-=col[j];
                col[j]=0;
                
            }
            else
            {   dp[i][j]=y;
            col[j]-=row[i];
                row[i]=0;
            }
        }
     }
     return dp;  
    }
};