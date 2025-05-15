class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
       vector<string>ans;
       int i=0;
       int n=words.size();
       while(i<n)
       {
        int j=i;
        while(j<n && groups[j]==groups[i])
        {
            j++;
        }
        ans.push_back(words[i]);
        i=j;
       } 
       return ans;
    }

};