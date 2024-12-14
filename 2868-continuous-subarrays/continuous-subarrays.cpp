class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
     long long ans=0;
     priority_queue<pair<int,int>>pq1;
     int temp=0;
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq2;
     for(int i=0;i<nums.size();i++)
     {
        while(!pq1.empty() && pq1.top().first-nums[i]>2)
        {
            temp=max(temp,pq1.top().second+1);
            pq1.pop();
        }
         while(!pq2.empty() && pq2.top().first-nums[i]<-2)
        {
            temp=max(temp,pq2.top().second+1);
            pq2.pop();
        }
        ans+=(i-temp+1);
        pq1.push({nums[i],i});
         pq2.push({nums[i],i});
     } 
     return ans;
    }
};