class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
         double ans=0.00000;
      int n=p.size();
      for(int i=0;i<n-2;i++)
      {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
               double x=0.00000;
               x=0.50000*abs(p[i][0]*(p[j][1]-p[k][1])+ p[j][0]*(p[k][1]-p[i][1])+p[k][0]*(p[i][1]-p[j][1]));
               ans=max(ans,x);
            }
        }
      }
return ans;
    }
};