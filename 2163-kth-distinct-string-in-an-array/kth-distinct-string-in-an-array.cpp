class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
       unordered_map<string ,int>mp;
       for(string itr:arr)
       {
        mp[itr]++;
       } 
       int m=0;
       for(string itr:arr)
       {
        if(mp[itr]==1 && k==1)
        {
            return itr;
        }
        if(mp[itr]==1 && k>1)
        {
            --k;
        }
       }
       return "";
    }
};