class Solution {
    bool static comp(vector<int>&a,vector<int>&b)
    {
        return a[0]>b[0];
    }
    int findpar(int node,vector<int>&parent)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findpar(parent[node],parent);
    }
    bool unionn(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        u=findpar(u,parent);
        v=findpar(v,parent);
        if(u!=v)
        {
            if(rank[u]<rank[v])
            {
                parent[u]=v;
            }
            else if(rank[u]>=rank[v])
            {
                parent[v]=u;
            }
            return true;
        }
        return false;
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
       vector<int>pa(n+1);
       vector<int>pb(n+1);
       vector<int>ar(n+1);
       vector<int>br(n+1);
       sort(edges.begin(),edges.end(),comp);
       for(int i=0;i<pa.size();i++)
       {
        pa[i]=i;
        pb[i]=i;
        ar[i]=1;
        br[1]=1;
       } 
       int re=0;
       int ma=1;
       int mb=1;
       for(auto itr:edges)
       {
        if(itr[0]==3)
        {
            bool ta=unionn(itr[1],itr[2],pa,ar);
            bool tb=unionn(itr[1],itr[2],pb,br);
            if(ta==true)
            {
                ma++;
            }
            if(tb==true)
            {
                mb++;
            }
            if(ta==false && tb==false)
            {
                ++re;
            }
        }
        else if(itr[0]==1)
        {
            bool ta=unionn(itr[1],itr[2],pa,ar);
            if(ta==true)
            {
                ++ma;
            }
            else
            {
                ++re;
            }
        }
        else
        {
            bool tb=unionn(itr[1],itr[2],pb,br);
            if(tb==true)
            {
                ++mb;
            }
            else
            {
                ++re;
            }
        }
       }
       if(ma!=n || mb!=n)
       {
        return -1;
       }
       return re;
    }
};