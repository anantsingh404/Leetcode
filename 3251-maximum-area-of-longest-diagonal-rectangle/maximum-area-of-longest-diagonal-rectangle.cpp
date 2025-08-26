class Solution {
public:
static bool cmp(vector<int>a,vector<int>b)
{
    int x=a[0]*a[0]+a[1]*a[1];
    int y=b[0]*b[0]+b[1]*b[1];
    if(x==y)
    {
        return a[0]*a[1]>=b[0]*b[1];
    }
    return x>=y;
}
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
      sort(d.begin(),d.end(),cmp)  ;
      return d[0][0]*d[0][1];
    }
};