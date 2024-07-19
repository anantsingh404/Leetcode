class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
     vector<int>ans;
     int n=matrix.size();
     int m=matrix[0].size();
     for(int i=0;i<n;i++)
     {
        for(int  j=0;j<m;j++)
        {
        int x=i;
        int y=0;
        int mini=INT_MAX;
        for(int y=0;y<m;y++)
        {
            mini=min(mini,matrix[i][y]);
        }
        int maxi=INT_MIN;
        x=0;
        y=j;
        for(int x=0;x<n;x++)
        {
            maxi=max(maxi,matrix[x][y]);
        }
        if(matrix[i][j]==mini && matrix[i][j]==maxi)
        {
            ans.push_back(matrix[i][j]);
        }
        }
     } 
     return ans;  
    }
};