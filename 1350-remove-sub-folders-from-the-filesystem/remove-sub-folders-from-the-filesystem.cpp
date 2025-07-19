class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
         sort(folder.begin(),folder.end());
      set<string>st;
      for(int i=0;i<folder.size();i++)
      {
          bool ans=true;
          string flag;
           int j=0;
          while(j<folder[i].size()){
         
            flag.push_back(folder[i][j]);
            int k=j+1;
            while(k<folder[i].size() && folder[i][k]!='/'){
            flag.push_back(folder[i][k]);
            k++;
            }
            if(st.find(flag)!=st.end())
            {
                ans=false;
                break;
            }
            j=k;
          }
          if(ans)
          {
            st.insert(folder[i]);
          }

      }
      vector<string>res;
      for(auto itr:st)
      {
        res.push_back(itr);
      }
      return res;
    }
};