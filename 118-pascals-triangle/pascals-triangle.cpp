class Solution {
public:
    vector<vector<int>> generate(int n) {
       vector<vector<int>>ans;
       vector<int>prev;
       prev.push_back(1);
       ans.push_back(prev);
       while(n>1)
       {
        vector<int>temp;
        temp.push_back(prev[0]);
        for(int i=0;i<prev.size()-1;i++)
        {
          temp.push_back(prev[i]+prev[i+1]);
        }
        temp.push_back(prev[prev.size()-1]);
        ans.push_back(temp);
        prev=temp;
        --n;
       }
       return ans;

    }
};