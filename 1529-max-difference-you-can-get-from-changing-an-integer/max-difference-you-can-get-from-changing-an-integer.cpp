class Solution {
public:
    int maxDiff(int num) {
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
            bool flag=false;
            for(int k=0;k<x.size();k++)
            {  
                int a=x[k]-'0';
                if(k==0 && j==0 && a==i)
                {  flag=true;
                    break;
                }
                if(a==i)
                {  // cout<<x<<endl;
                    x[k]='0'+j;
                }
            }
            if(flag)
            {
                continue;
            }
            int y=stoi(x);
            maxi=max(maxi,y);
            mini=min(mini,y);
        }
      }
     // cout<<maxi<<" "<<mini<<endl;
      return maxi-mini;
    }
};