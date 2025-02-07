class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
       unordered_map<int,int>col;
       unordered_map<int,int>dist;
       vector<int>ans;
       for(int i=0;i<queries.size();i++)
       {
        int x=queries[i][0];
        int y=queries[i][1];
        if(dist[x]>0 && dist[x]==y)
        {
            ans.push_back(col.size());
        }
        else if(dist[x]<1)
        {
            dist[x]=y;
            col[y]++;
            ans.push_back(col.size());
        }
        else
        {
            col[dist[x]]--;
            if(col[dist[x]]<1)
            {
                col.erase(dist[x]);
            }
            dist[x]=y;
            col[y]++;
            ans.push_back(col.size());

        }
       }
       return ans;

    }
};