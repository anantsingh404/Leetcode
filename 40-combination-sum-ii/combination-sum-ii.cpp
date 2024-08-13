class Solution {
public:
void solve(vector<int>a,int idx,vector<vector<int>>&ans,vector<int>flag,int b)
  {   if(b<0)
  {
      return;
  }
      if(idx==a.size())
      {
          if(b==0)
          {
              ans.push_back(flag);
              return;
          }
          return;
      }
        
        if(b<0 || idx>=a.size())
        {
            return;
      }
      
      if(a[idx]<=b)
      {
          flag.push_back(a[idx]);
          solve(a,idx+1,ans,flag,b-a[idx]);
          flag.pop_back();
      }
     while(idx+1<a.size() && a[idx]==a[idx+1]){
            idx++;
        }
          solve(a,idx+1,ans,flag,b);
  }
    vector<vector<int>> combinationSum2(vector<int>& arr, int b) {
         
     
       // vector<int>ds;
       sort(arr.begin(),arr.end());
       vector<vector<int>>ans;
       // vector<vector<int>>ans;
        vector<int>flag;
        solve(arr,0,ans,flag,b);
        set<vector<int>>st;
        for(auto itr:ans)
        {
            st.insert(itr);
        }
        ans.clear();
        for(auto itr:st)
        {
            ans.push_back(itr);
        }
        return ans;
    }
};