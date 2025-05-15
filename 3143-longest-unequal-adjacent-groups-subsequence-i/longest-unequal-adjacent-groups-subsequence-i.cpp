class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
       vector<string>ans;
       int i=0;
       while(i<words.size())
       {
        int j=i;
        while(j<words.size() && groups[j]==groups[i])
        {
            j++;
        }
        ans.push_back(words[i]);
        i=j;
       } 
       return ans;
    }

};