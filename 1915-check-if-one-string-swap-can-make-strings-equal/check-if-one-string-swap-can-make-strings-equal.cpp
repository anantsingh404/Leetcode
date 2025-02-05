class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
      int count=0;
    set<int>x,y;
      for(int i=0;i<s1.size();i++)
      {
        if(s1[i]!=s2[i])
        {
            ++count;
            x.insert(s1[i]);
            y.insert(s2[i]);
        }
      } 
      return (count==2 || count==0) && x==y; 
    }
};