class Solution {
public:
int solve(int i,int k,vector<vector<int>>&edge,int parent)
{
    if(k<0)
    {
        return 0;
    }
    int ans=1;
    for(auto itr:edge[i])
    {
        if(itr!=parent && k>0)
        {
           ans+=(solve(itr,k-1,edge,i));
        }
    }
    return ans;
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1; 
    int m = edges2.size() + 1; 


    vector<vector<int>> tree1(n), tree2(m);
    for (auto& edge : edges1) {
        tree1[edge[0]].push_back(edge[1]);
        tree1[edge[1]].push_back(edge[0]);
    }
    for (auto& edge : edges2) {
        tree2[edge[0]].push_back(edge[1]);
        tree2[edge[1]].push_back(edge[0]);
    }
    vector<int>dist(m,0);
    int maxi=0;
    for(int i=0;i<m;i++)
    {
        int temp=solve(i,k-1,tree2,-1);
        dist[i]=temp;
       // cout<<dist[i]<<endl;
        maxi=max(maxi,dist[i]);
    }
  //  cout<<maxi<<endl;
    vector<int>dist2(n,0);
    for(int i=0;i<n;i++)
    {
        int temp=solve(i,k,tree1,-1);
        cout<<temp<<endl;
        dist2[i]=temp;
    }
    vector<int>ans(n,0);
    for(int i=0;i<n;i++)
    {
        ans[i]=maxi+dist2[i];
    }
    return ans;
        
    }
};