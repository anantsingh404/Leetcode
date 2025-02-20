class Solution {
public:
vector<string>ans;
int n;
 unordered_map<string,int>mp;
 void solve(int i,string s)
 {  if(ans.size()>0)
 {
    return ;
 }
    if(i==n)
    {
        if(mp[s]<1)
        {
            ans.push_back(s);
            return ;
        }
        else
        {
            return ;
        }
    }
    s.push_back('0');
    solve(i+1,s);
    s.pop_back();
    s.push_back('1');
    solve(i+1,s);
    s.pop_back();
    return ;
 }
    string findDifferentBinaryString(vector<string>& nums) {
      n=nums.size();  
     
      for(int i=0;i<nums.size();i++)
      {
        mp[nums[i]]++;
      }
      solve(0,"");
      return ans[0];
    }
};