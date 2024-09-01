class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& ori, int m, int n) {
        vector<vector<int>>dp;
        if(m*n!=ori.size())
        {
            return dp;
        }
        for(int i=0;i<ori.size();i+=n)
        {
        vector<int>temp;
        for(int j=i;j<i+n;j++)
        {
            temp.push_back(ori[j]);
        }
        dp.push_back(temp);
        }
        return dp;
    }
};