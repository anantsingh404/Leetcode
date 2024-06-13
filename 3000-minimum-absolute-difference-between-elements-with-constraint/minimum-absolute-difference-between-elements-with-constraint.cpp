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
          auto itr=st.upper_bound(nums[j]);
          if(itr==st.end())
          {
            --itr;
          }
          auto itr2=st.lower_bound(nums[j]); 
          if(itr2==st.end())
          {
            --itr2;
          }
         // auto itr3;
          if(itr2!=st.begin())
          {
auto itr3=itr2;
--itr3;
ans=min(ans,abs((*itr3)-nums[j])); 
          }
          cout<<*itr<< " "<<*itr2<<endl;
          ans=min(ans,abs((*itr)-nums[j]));
          ans=min(ans,abs((*itr2)-nums[j])); 
          
        }
        
        j++;
        
    }  
    return ans;
    }
};