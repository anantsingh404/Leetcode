class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int flag=1;
    vector<int>res;
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++)
    {
        int j=0;
        int k=i;
        vector<int>ans;
        while(j<m && k>=0)
        {
            ans.push_back(mat[k][j]);
            j++;
            k--;
        }
        if(flag==0)
        {
            reverse(ans.begin(),ans.end());
        }
        flag=flag^1;
        for(int p=0;p<ans.size();p++)
        {
            res.push_back(ans[p]);
        }
    } 

    for(int i=1;i<m;i++)
    {
        int j=n-1;
        int k=i;
        vector<int>ans;
        while(j>=0 && k<m)
        {
            ans.push_back(mat[j][k]);
            j--;
            k++;
        }
        if(flag==0)
        {
            reverse(ans.begin(),ans.end());
        }
        flag=flag^1;
        for(int p=0;p<ans.size();p++)
        {
            res.push_back(ans[p]);
        }

    } 
return res;
    }
};