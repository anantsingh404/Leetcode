class Solution {
public:
bool cc(vector<int>v)
{
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i+1]-v[i]!=1)
        {
            return false;
        }
    }
    return true;
}
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>mp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:hand)
        {
            mp[x]++;
        }
        for(auto u:mp)
        {
            pq.push(u.first);
        }
        while(!pq.empty())
        {
            vector<int>temp;
            for(int i=0;i<groupSize;i++)
            {
                if(!pq.empty())
                {
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }
                for(int i=0;i<temp.size();i++)
                {
                    if(--mp[temp[i]]>0)
                    {
                        pq.push(temp[i]);
                    }
                }
                if(temp.size()==groupSize)
                {
                    if(!cc(temp))
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        
        return true;
    }
};