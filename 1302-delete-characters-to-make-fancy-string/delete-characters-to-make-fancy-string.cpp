class Solution {
public:
    string makeFancyString(string s) {
      string temp;
      int count=0;
      int i=0;
      while(i<s.size())
      { if(!temp.empty())
      {
        if(temp.back()!=s[i])
        {
            count=0;
        }
      }
        if(temp.empty() || count<2)
        {
          temp.push_back(s[i]);
          ++count;
        }
        i++;
      }
      return temp;  
    }
};