class Solution {
public:
int m;
bool check(string &temp)
{
    
    int n=temp.size();
    for(int i=1;i<n;i++)
    {
        if(temp[i]==temp[i-1] && temp[i]=='0')
        {
            return false;
        }
    }
    return true;
}
void solve(int n,vector<string>&ans,string &temp,int count)
{
    if(n==0)
    {   
        if(check(temp))
        {
            ans.push_back(temp);
            return ;
        }
        else
        {
            return;
        }
    }
    temp.push_back('0');
    solve(n-1,ans,temp,count);
    temp.pop_back();
    temp.push_back('1');
    solve(n-1,ans,temp,count+1);
    temp.pop_back();
    return;
}
    vector<string> validStrings(int n) {
      vector<string>ans;
      string temp="";
      solve(n,ans,temp,0);
      return ans;  
    }
};