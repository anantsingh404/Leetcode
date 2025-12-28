class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
      int count=0;
      int n=grid.size();
      int m=grid[0].size();
      for(int i=0;i<n;i++)
      {
        int idx=upper_bound(grid[i].rbegin(),grid[i].rend(),-1)-grid[i].rbegin();
        //cout<<idx<<endl;
       // cout<<count<<endl;
       count+=idx;
      }
      return count;

    }
};