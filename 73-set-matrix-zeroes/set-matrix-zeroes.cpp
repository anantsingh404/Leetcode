class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int firstrow=0;
        int firstcol=0;
        int j=0;
        int i=0;
        while(j<m)
        {
            if(mat[i][j]==0)
            {
                firstrow=1;
            }
            ++j;
        }
        j=0;
        while(i<n)
        {
            if(mat[i][j]==0)
            {
                firstcol=1;
            }
            ++i;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    mat[0][j]=0;
                    mat[i][0]=0;
                }
            }
        }
        for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][0] == 0 || mat[0][j] == 0) {
                mat[i][j] = 0;
            }
        }
    }
    if (firstrow) {
        for (int j = 0; j < m; j++) {
            mat[0][j] = 0;
        }
    }

    
    if (firstcol) {
        for (int i = 0; i < n; i++) {
            mat[i][0] = 0;
        }
    }
        
    }
};