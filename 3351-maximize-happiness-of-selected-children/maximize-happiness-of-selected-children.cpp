class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
      sort(h.begin(),h.end());
      long long ans=0;
      int j=h.size()-1;
      int dec=0;
      while(j>=0 && k>0)
      {
          ans+=max(0,h[j]-dec);
          ++dec;
          --j;
          --k;
      }
      return ans;


    }
};