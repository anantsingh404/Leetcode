class Solution {
public:
    int maxOperations(string s) {
       int n=s.size();
       string temp;
       int ans=0;
       unordered_map<char,int>mp;
       for(int i=0;i<n;i++)
       {
        if(temp.empty())
        {
            temp.push_back(s[i]);
        }
        else if(s[i]=='0' && temp.back()=='0')
        {
            continue;
        }
        else
        {
            temp.push_back(s[i]);
        }
       }
       n=temp.size();
       for(int i=0;i<n;i++)
       {
        if(temp[i]=='1')
        {
            mp['1']++;
        }
        else
        {
            ans+=mp['1'];
        }

       }
       return ans;
    }
};