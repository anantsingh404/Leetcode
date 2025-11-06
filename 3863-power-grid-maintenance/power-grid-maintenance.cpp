class Solution {
public:
unordered_map<int,int>mp1;
void dfs(int idx,vector<vector<int>>&adj,set<int>&st,vector<int>&vis,int &k)
{
    if(vis[idx]!=0)
    {
        return;
    }
    vis[idx]=1;
    st.insert(idx);
    mp1[idx]=k;
    for(int itr:adj[idx])
    {
        if(vis[itr]==0)
        {
            dfs(itr,adj,st,vis,k);
        }
    }
}
    vector<int> processQueries(int n, vector<vector<int>>& con, vector<vector<int>>& q) {
        vector<vector<int>>adj(n+1);
        mp1.clear();
        vector<int>vis(n+1,0);
        for(int i=0;i<con.size();i++)
        {
            int x=con[i][0];
            int y=con[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        unordered_map<int,set<int>>mp2;
        int k=1;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {   set<int>st;
                dfs(i,adj,st,vis,k);
                mp2[k]=st;
                k++;
            }
        }
        vector<int>ans;
        for(int i=0;i<q.size();i++)
        {
            int x=q[i][0];
            int y=q[i][1];
            if(x==1)
            {
                int p=mp1[y];
                auto & st=mp2[p];
                if(st.find(y)!=st.end())
                {
                    ans.push_back(y);
                }
                else if(st.size()==0)
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(*st.begin());
                }
            }
            if(x==2)
            {
                int p=mp1[y];
                auto & st=mp2[p];
                if(st.find(y)!=st.end())
                {
                    st.erase(y);
                }
                
            }
        }
        return ans;
        
    }
};