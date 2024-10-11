class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
       vector<pair<int,int>>at;
       int n=times.size();
       for(int i=0;i<n;i++)
       {
            at.push_back({times[i][0],i});
       }
       sort(at.begin(),at.end());
    priority_queue<int,vector<int>,greater<int>>av;
    for(int i=0;i<times.size();i++)
    {
        av.push(i);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>lq;
    for(auto & arrival:at)
    {
        int x=arrival.first;
        int fi=arrival.second;
        while(!lq.empty() && lq.top().first<=x)
        {
            av.push(lq.top().second);
            lq.pop();
        }
        int ch=av.top();
        av.pop();
        if(fi==t)
        {
            return ch;
        }
        lq.push({times[fi][1],ch});
    }
        return -1;
    }
};