class Solution {
public:
   int maxCandies(vector<int>& open, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans=0;
        queue<int>q;
        int n=open.size();
        vector<bool>haveBox(n,0);
        vector<bool>haveKey(n,0);
        for(int &x:initialBoxes) 
        {
            if(open[x]) 
            {
                q.push(x);
            }
             else 
             {
                haveBox[x] = true;
             }
        }
        while(!q.empty()) 
        {
            int id = q.front();
            q.pop();
            ans+=candies[id];
            for(int &b: containedBoxes[id]) 
            {
                if(open[b] || haveKey[b]) 
                {
                    q.push(b);
                }
                else
                {
                     haveBox[b]=true;
                }
            }
            for(int &k:keys[id]) 
            {
                haveKey[k]=true;
                if(haveBox[k]) 
                {
                    q.push(k);
                    haveBox[k]=false;
                }
            }
        }
        return ans;
    }

};