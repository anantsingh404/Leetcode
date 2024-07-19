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
        int y=0;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int y=0;y<m;y++)
        {
            mini=min(mini,matrix[i][y]);
        }
        y=0;
        for(int y=0;y<n;y++)
        {
            maxi=max(maxi,matrix[y][j]);
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