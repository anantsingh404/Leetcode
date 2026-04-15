class Solution {
public:
    int closestTarget(vector<string>& w, string t, int si) {
        int ans=INT_MAX;
        int n=w.size();
      for(int i=0;i<w.size();i++)
      {
        if(w[i]==t)
        {
            ans=min(ans,abs(i-si));
            ans=min(ans,n-abs(i-si));
        }
      } 
      if(ans==INT_MAX)
      {
        return -1;
      } 
      return ans;
    }
};