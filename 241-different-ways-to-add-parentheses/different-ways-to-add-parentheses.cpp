class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
      vector<int>ans;
      if(exp.size()==1)
      {  int x=exp[0]-'0';
        return {x};
      }
      if(exp.size()==2)
      {
        int x=exp[0]-'0';
        int y=exp[1]-'0';
        return {x*10+y};
      }
      for(int i=0;i<exp.size();i++)
      {
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*')
        {
            vector<int>x=diffWaysToCompute(exp.substr(0,i));
            vector<int>y=diffWaysToCompute(exp.substr(i+1,exp.size()-i+1));
            for(auto itr1:x)
            {
                for(auto itr2:y)
                {   if(exp[i]=='+'){
                    ans.push_back(itr1+itr2);
                }
                 if(exp[i]=='-'){
                    ans.push_back(itr1-itr2);
                }
                if(exp[i]=='*'){
                    ans.push_back(itr1*itr2);
                }
                }
            }
        }
      }
      return ans;

    }
};