class Solution {
public:
    bool isCircularSentence(string s) {
      for(int i=0;i<s.size();i++)
      {
if(s[i]==' ')
{
    if(s[i-1]!=s[i+1])
    {
        return false;
    }
}
      } 
      int n=s.size();
      if(s[0]!=s[n-1])
      {
        return false;
      } 
      return true;
    }
};