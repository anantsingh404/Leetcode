class Solution {
public:
bool Check(vector<int>&x,int mid,int m,int k)
{
   int flag=0;
   int count=0;
    for(int i=0;i<x.size();i++)
    {
        
        if(x[i]<=mid)
        {
            ++flag;
        }
        if(x[i]>mid)
        {
            flag=0;
        }
        if(flag==k)
        {
            ++count;
            flag=0;
        }
    }
    if(count>=m)
    {
        return true;
    }
    return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
      int n=bloomDay.size();
       
      int maxi=*max_element(bloomDay.begin(),bloomDay.end());
      int i=1;
      int j=maxi;
      int ans=-1;
      while(i<=j)
      {
        int mid=(i+j)/2;
        if(Check(bloomDay,mid,m,k))
        {
            ans=mid;
            j=mid-1;
        }
        else
        {
            i=mid+1;
        }
      }
      return ans;
    }
};