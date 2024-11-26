class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
      
      vector<int>ans(n,0);
      int count=0;
      int  temp=-1;
      for(int i=0;i<edges.size();i++)  
      {
        int y=edges[i][1];
        ans[y]++;
      }
      for(int i=0;i<n;i++)
      {
        if(ans[i]==0)
        {
            ++count;
            temp=i;
            if(count>=2)
            {
                return -1;
            }
        }
      }
      return temp;
    }
};