class Solution {
public:
    int findMinDifference(vector<string>& time) {
       vector<int>ans;
       for(int i=0;i<time.size();i++)
       {
        string x=time[i].substr(0,2);
        string y=time[i].substr(3,2);
        int p=stoi(x);
        int q=stoi(y);
        p=p*60;
        p+=q;
        ans.push_back(p);
       }
       sort(ans.begin(),ans.end());
       int res=INT_MAX;
       for(int i=1;i<ans.size();i++)
       {
        res=min(res,ans[i]-ans[i-1]);
       }
       res=min(res,24*60-ans[ans.size()-1]+ans[0]);
       return res;

    }
};