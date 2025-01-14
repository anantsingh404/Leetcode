class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
     int count=0;
     int i=0;
     int n=grid.size();
     int m=grid[0].size();
     vector<int>res;
     while(i<n)
     {  vector<int>ans;
        if(i%2==0){
        for(int j=0;j<grid[0].size();j++)
        {
           if(j%2==0)
           {
            ans.push_back(grid[i][j]);
           }
        }
        for(int k=0;k<ans.size();k++)
        {
            res.push_back(ans[k]);
        }
     }
      else{
        for(int j=0;j<grid[0].size();j++)
        {
           if(j%2==1)
           {
            ans.push_back(grid[i][j]);
           }
        }
        reverse(ans.begin(),ans.end());
        for(int k=0;k<ans.size();k++)
        {
            res.push_back(ans[k]);
        }
     }
     i++;
     } 
     return res;  
    }
};