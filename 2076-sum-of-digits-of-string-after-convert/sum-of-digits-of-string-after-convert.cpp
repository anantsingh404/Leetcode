class Solution {
public:
    int getLucky(string s, int k) {
      string flag;
      for(int i=0;i<s.size();i++)
      {
        int x=s[i]-'a'+1;
        string y=to_string(x);
        flag+=y;
      }
      while(k--)
      {
        //string x=to_string(sum);
        int temp=0;
        for(int j=0;j<flag.size();j++)
        {
            temp+=flag[j]-'1'+1;
        }
    flag=to_string(temp);
      } 
      return stoi(flag); 
    }
};