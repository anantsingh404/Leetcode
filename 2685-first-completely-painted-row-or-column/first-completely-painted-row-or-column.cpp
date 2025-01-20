class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
     int ans=1e9;
     int n=mat.size();
     int m=mat[0].size();
     unordered_map<int,int>mp;
     for(int i=0;i<arr.size();i++)
     {
        mp[arr[i]]=i+1;
     }
     for(int i=0;i<n;i++)
     {  int flag=0;
        for(int j=0;j<m;j++)
        {
            flag=max(flag,mp[mat[i][j]]-1);
        }
        ans=max(ans,flag);
     }
     for(int i=0;i<n;i++)
     {  int flag=0;
        for(int j=0;j<m;j++)
        {
            flag=max(flag,mp[mat[i][j]]-1);
        }
        ans=min(ans,flag);
     }
     for(int j=0;j<m;j++)
     {  int flag=0;
        for(int i=0;i<n;i++)
        {
            flag=max(flag,mp[mat[i][j]]-1);
        }
        ans=min(ans,flag);
     }
return ans;
    }
};