class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
       long long sum=0;
       int count=0;
       int mini=INT_MAX;
       for(int i=0;i<mat.size();i++)
       {
        for(int j=0;j<mat[0].size();j++)
        {
            sum+=abs(mat[i][j]);
            if(abs(mat[i][j])<mini)
            {
                mini=abs(mat[i][j]);
            }
            if(mat[i][j]<0)
            {
                ++count;
            }
        }
       }
       if(count%2==0)
       {
        return sum;
       }
       return sum-2*mini; 
    }
};