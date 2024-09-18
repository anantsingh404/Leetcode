class Solution {
public:
static bool cmp(string &a,string &b)
{
   return a+b<b+a;
}
    string largestNumber(vector<int>& nums) {
      vector<string>st;
      for(int i=0;i<nums.size();i++)
      {
        string x=to_string(nums[i]);
        st.push_back(x);
      } 
      sort(st.begin(),st.end(),cmp);
      string ans;
      for(int i=0;i<st.size();i++)
      {
        ans=st[i]+ans;
      } 
      if(ans[0]=='0')
      {
        return "0";
      }
      return ans;
    }
};