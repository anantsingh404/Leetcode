class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       int ans=0;

    vector<int>row;
    vector<int>col;
    for(int i=0;i<n;i++)
    {
        int sum=0;
  for(int j=0;j<m;j++)
  {
    sum+=grid[i][j];
   
  }
   row.push_back(sum);
  
    }
     for(int j=0;j<m;j++)
    {
        int sum=0;
  for(int i=0;i<n;i++)
  {
    sum+=grid[i][j];
    
  }
  col.push_back(sum);
  
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        
  for(int j=0;j<m;j++)
  {
    if((row[i]>1 || col[j]>1) && grid[i][j]==1)
    {
        ++count;
    }
  }
    }
  return count;
    }
    
    
    
};