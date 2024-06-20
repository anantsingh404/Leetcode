class Solution {
public:
bool check(vector<int>&pos,int m,int mid)
{
    int count=1;
    int j=0;
    for(int i=0;i<pos.size();i++)
    {
        if(pos[i]-pos[j]>=mid)
        {
            count++;
            j=i;
        }
        
    }
    if(count>=m)
    {
        return true;
    }
    return false;
}
    int maxDistance(vector<int>& pos, int m) {
      int maxi=*max_element(pos.begin(),pos.end());
      int mini=1;
      int ans=1;
      sort(pos.begin(),pos.end());
      while(mini<=maxi)
      {
        int mid=(mini+maxi)/2;
        if(check(pos,m,mid))
        {
        ans=mid;
        mini=mid+1;
        }
        else
        {
            maxi=mid-1;
        }
      } 
      return ans; 
    }
};