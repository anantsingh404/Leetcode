class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
      unordered_map<int,int>mp1,mp2;
      vector<int>ans;
      for(int i=0;i<A.size();i++)
      {
        mp1[A[i]]++;
        mp2[B[i]]++;
        int count=0;
        for(int j=1;j<=50;j++)
        {
            if(mp1[j]>0 && mp2[j]>0)
            {
                ++count;
            }
        }
        ans.push_back(count);
      } 
      return ans; 
    }
};