class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& co, int k) {
        int n=co.size();
        int sum=0;
        int count=0;
        for(int i=1;i<n;i++)
        {
          if(co[i]==co[i-1])
          {
            sum=i;
          }
          if(i-sum+1>=k)
          {
            ++count;
          }
        }
        if(co[0]!=co[n-1]){
            int temp=0;
        for(int i=0;i<k-1;i++)
        {   if(i>0 && co[i]==co[i-1])
            {
                break;
            }
            if(n-sum-temp+(i+1)>=k)
            {   ++temp;
                ++count;
            }
            
        
        }
        }

        return count;
        
    }
};