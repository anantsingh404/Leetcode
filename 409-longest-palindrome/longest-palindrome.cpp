class Solution {
public:
    int longestPalindrome(string s) {
    unordered_map<int,int>mp;
    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
    }   
    int odd=0;
    int sum=0;
    for(auto itr:mp)
    {
        if(itr.second%2)
        {
            sum+=itr.second-1;
            ++odd;
        }
        else
        {
            sum+=itr.second;
        }
    }
    if(odd)
    {
        return sum+1;
    }
    return sum;

    }
};