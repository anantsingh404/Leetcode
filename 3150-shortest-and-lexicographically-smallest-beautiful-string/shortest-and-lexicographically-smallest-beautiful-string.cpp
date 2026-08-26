class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
       vector<string>ans;
        for(int i=0;i<s.size();i++)
        {
            int count=0;
            string flag;
            for(int j=i;j<s.size();j++)
            {
                if(s[j]=='1')
                {
                    ++count;
                }
                  flag.push_back(s[j]);
                if(count==k)
                {
                    ans.push_back(flag);
                }
            }
        }
        sort(ans.begin(),ans.end());
        int smallest=INT_MAX;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i].size()<smallest)
            {
                smallest=ans[i].size();
            }
        }
        if(ans.empty())
        {
            return "";
        }
        string res;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i].size()==smallest)
            {
                res=ans[i];
                break;
            }
        }
        return res;
    }
};