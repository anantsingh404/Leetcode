class Solution {
public:
set<string>ans;
void solve(int n,string & s)
{
    if(n==0 && !s.empty())
    {
        ans.insert(s);
        return ;
    }
    if(n==0)
    {
        return ;
    }
    if(s.empty())
    {  s.push_back('a');
        solve(n-1,s);
        s.pop_back();
         s.push_back('b');
        solve(n-1,s);
        s.pop_back();
         s.push_back('c');
        solve(n-1,s);
        s.pop_back();
    }
    else if(s.back()=='a')
    {   s.push_back('b');
        solve(n-1,s);
        s.pop_back();
        s.push_back('c');
        solve(n-1,s);
        s.pop_back();
    }
    else if(s.back()=='b')
    {   s.push_back('a');
        solve(n-1,s);
        s.pop_back();
        s.push_back('c');
        solve(n-1,s);
        s.pop_back();
    }
    else
    {  
        s.push_back('a');
        solve(n-1,s);
        s.pop_back();
        s.push_back('b');
        solve(n-1,s);
        s.pop_back();
    }
}
    string getHappyString(int n, int k) {
        string s;
      solve(n,s); 
      int i=1;
      for(string itr:ans)
      {
        if(i==k)
        {
            return itr;
        }
        i++;
      } 
      return "";
    }
};