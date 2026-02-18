class Solution {
public:
    bool hasAlternatingBits(int n) {
     string ans="";
     for(int i=31;i>=0;i--){
   if(ans.empty())
   {
    if((1<<i)&n){
        ans.push_back('1');
    }
   }
   else
   {
    if((1<<i)&n)
    {
        ans.push_back('1'); 
    }
    else
    {
          ans.push_back('0');
    }
   }
     }
     for(int i=0;i<ans.size()-1;i++)
     {
        if(ans[i]==ans[i+1])
        {
            return false;
        }
     }
     return true;
    }
};