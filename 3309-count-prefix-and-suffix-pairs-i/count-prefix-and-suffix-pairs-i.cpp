class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
      int n=words.size();
      int count=0;
      for(int i=0;i<n-1;i++)
      { 
        int x=words[i].size();
        for(int j=i+1;j<n;j++)
        {
           if((int)words[j].size()<x)
           {
            continue;
           }
           else
           {
           string a = words[j].substr(0, x); // Prefix
                int suffixStart = words[j].size() - x; 
                
                // Ensure suffixStart is valid
                if (suffixStart < 0) continue;

                string b = words[j].substr(suffixStart, x); // Suffix
                if (a == words[i] && b == words[i]) {
                    ++count;
                }
           }
        }
      }
      return count;  
    }
};