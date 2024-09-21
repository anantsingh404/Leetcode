class Solution {
public:
    vector<int> lexicalOrder(int n) {
       vector<string>ans;
       for(int i=1;i<=n;i++)
       {
        string x=to_string(i);
        ans.push_back(x);
       }
       sort(ans.begin(),ans.end());
       vector<int>res;
       for(int i=0;i<ans.size();i++)
       {
        int x=stoi(ans[i]);
        res.push_back(x);
       }
       return res;

    }
};