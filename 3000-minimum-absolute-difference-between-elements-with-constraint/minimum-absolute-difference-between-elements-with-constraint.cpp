class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
    int j=0;
    int i=0;
    int ans=INT_MAX;
    int n=nums.size();
    multiset<int>st;
    while(j<n)  

    {  
        
     if(j>=x){
        st.insert(nums[i]);
        i++;
        }
        
        if( !st.empty() && j>=x)
        {
          
          auto itr2=st.lower_bound(nums[j]); 
          if(itr2==st.end())
          {
            --itr2;
          }
          if(itr2!=st.begin())
          {
         auto itr3=itr2;
         --itr3;
         ans=min(ans,abs((*itr3)-nums[j])); 
          }
          ans=min(ans,abs((*itr2)-nums[j])); 
          
        }
        
        j++;
        
    }  
    return ans;
    }
};