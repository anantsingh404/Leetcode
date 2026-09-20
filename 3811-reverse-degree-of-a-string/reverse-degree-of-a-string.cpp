class Solution {
public:
    int reverseDegree(string s) {
      int sum=0;
      for(int i=0;i<s.size();i++)
      {
        sum+=abs(26-abs((s[i]-'a')))*(i+1);
       // cout<<sum<<endl;
      }  
      return sum;
    }
};