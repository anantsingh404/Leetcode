class Solution {
public:
    int minMaxDifference(int num) {
      int maxi=INT_MIN;
      int mini=INT_MAX;
      for(int i=0;i<=9;i++)
      {
        for(int j=0;j<=9;j++)
        {
            if(i==j)
            {
                continue;
            }
                string x=to_string(num);
                for(int k=0;k<x.size();k++)
                {
                    if(x[k]=='0'+i)
                    {
                        x[k]='0'+j;
                    }
                }
                int y=stoi(x);
                maxi=max(maxi,y);
                 mini=min(mini,y);
            
        }
      }
      return maxi-mini;

    }
};