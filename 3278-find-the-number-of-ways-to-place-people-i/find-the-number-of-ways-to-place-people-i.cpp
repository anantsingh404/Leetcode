class Solution {
public:
    static bool cmp(vector<int>a,vector<int>b)
    {
        if(a[0]==b[0])
        {
            return a[1]>=b[1];
        }
        return a[0]<b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
      sort(points.begin(),points.end(),cmp);
        int count=0;
        for(int i=0;i<points.size();i++)
        {   
            for(int j=i+1;j<points.size();j++)
            {   int flag=0; 
                for(int k=i+1;k<j;k++)
                {
                    if(points[k][1]<=points[i][1] && points[k][1]>=points[j][1])
                    {
                        ++flag;
                    }
                }
             if(flag==0 && points[j][1]<=points[i][1])
             {
                 ++count;
             }
            }
        }
        return count;
        
    }
};