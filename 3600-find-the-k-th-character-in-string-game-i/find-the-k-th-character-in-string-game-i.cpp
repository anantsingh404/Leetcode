class Solution {
public:
    char kthCharacter(int k) {
      string x="a";
      while(x.size()<500)
      {
        string t=x;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='z')
            {
                t[i]='a';
            }
            else
            {
                t[i]=t[i]+1;
            }
        }
        x+=t;
      } 
      return x[k-1]; 
    }
};