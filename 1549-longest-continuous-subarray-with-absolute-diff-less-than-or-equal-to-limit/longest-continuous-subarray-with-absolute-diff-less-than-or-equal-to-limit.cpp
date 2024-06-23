class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
     unordered_map<int,int>mp;
     int n=nums.size();
     int j=0;
     int ans=1;
    // set<int>st;
      priority_queue<int>pq;
      priority_queue<int,vector<int>,greater<int>>pq2;
     for(int i=0;i<n;i++)
     {
       
       while(!pq2.empty() && nums[i]-pq2.top()>limit)
       {
        j=max(j,mp[pq2.top()]+1);
        pq2.pop();
       }
       
        while(!pq.empty() && pq.top()-nums[i]>limit)
        {   j=max(j,mp[pq.top()]+1);
            pq.pop();

        }
        if(pq.empty() || pq2.empty())
        {
            j=i;
        }
        

        
     pq2.push(nums[i]);
       pq.push(nums[i]);
        //st.insert(nums[i]);
        mp[nums[i]]=i;
        ans=max(ans,i-j+1);
        
     }   
     return ans;
    }
};