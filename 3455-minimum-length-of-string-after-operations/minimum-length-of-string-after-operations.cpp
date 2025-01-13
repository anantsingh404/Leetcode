class Solution {
public:
    int minimumLength(string s) {
    unordered_map<int,int>mp;
    for(int i=0;i<s.size();i++)
    {
        mp[s[i]-'a']++;
    }
    int ans=0;
    for(auto itr:mp)
    {
        int x=itr.second;
        if(x==3)
        {
            ans+=1;
        }
        else if(x>3 && x%2)
        {
            ans+=1;
        }
        else if(x>3 && x%2==0)
        {
            ans+=2;
        }
        else if(x==2)
        {
            ans+=2;
        }
        else
        {
            ans+=x;
        }
    }
    return ans;
    }
};