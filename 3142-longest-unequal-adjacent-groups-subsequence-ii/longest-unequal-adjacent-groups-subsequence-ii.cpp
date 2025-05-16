class Solution {
public:
int cal(string w1, string w2){
      int hamdist= 0;
      
      for (int k = 0; k < w1.size(); k++)
      {

          if (w1[k] != w2[k])
           {
                 hamdist++;
                 if (hamdist > 1) break;
           }
      }
      return hamdist;
  }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
       int n = words.size();
    vector<int> ans(n, 1); // Fix: Initialize all to 1
    int maxi = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (words[i].size() != words[j].size()) continue;

            int diff = 0;
            for (int k = 0; k < words[i].size(); k++) {
                if (words[i][k] != words[j][k]) {
                    ++diff;
                    if (diff > 1) break;
                }
            }
            if (diff == 1 && groups[i]!=groups[j]) {
                ans[i] = max(ans[i], ans[j] + 1);
                maxi = max(maxi, ans[i]);
            }
        }
    }

    int cg = -1;
    vector<string> res;
    string prev="";
    for (int i = n - 1; i >= 0; i--) {
        if(res.empty()){
        if (ans[i] == maxi && cg != groups[i]) {
            res.push_back(words[i]);
            --maxi;
            cg = groups[i];
            prev=words[i];
        }
        }
        else
        {
            if (ans[i] == maxi && cg != groups[i] && words[i].size()==res.back().size() && cal(words[i],prev)==1) {
            res.push_back(words[i]);
            --maxi;
            cg = groups[i];
            prev=words[i];
        } 
        }
    }

    reverse(res.begin(), res.end());
    return res;
    }
};