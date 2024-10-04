class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
       long long sum=accumulate(skill.begin(),skill.end(),1ll*0);
       unordered_map<long long,long long>mp;
       for(int i=0;i<n;i++)
       {
        mp[skill[i]]++;
       }
       if(sum%(n/2))
       {
        return -1;
       } 
       sum=sum/(n/2);
      // vector<pair<long,long>>vp;
       long long ans=0;
       unordered_map<long long,long long>mp1;
       for(auto itr:mp)
        {
            if(mp1[itr.first])
            {
                continue;
            }
         if(itr.first>=sum){
            return -1;
         }
         else if(mp.find(sum-itr.first)!=mp.end() && mp[sum-itr.first]==itr.second)
         {
            ans+=itr.first*(sum-itr.first)*(itr.first!=sum-itr.first?itr.second:itr.second/2);
            mp1[itr.first]++;
            mp1[sum-itr.first]++;

          
            }
         
         else
         {
            return -1;
         }
    }
    return ans;

    }
};