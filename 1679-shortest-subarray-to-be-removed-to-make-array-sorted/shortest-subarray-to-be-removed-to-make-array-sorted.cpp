class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        bool temp=true;
      vector<bool>left(n,false);
      vector<bool>right(n,false);
     
      set<pair<int,int>>st;
      left[0]=true;
      right[n-1]=true;
      for(int i=1;i<n;i++)
      {
        if(arr[i]>=arr[i-1])
        {
            left[i]=true;
        }
        else
        {
            break;
        }
      }
       for(int i=n-2;i>=0;i--)
      {
        if(arr[i]<=arr[i+1])
        {
            right[i]=true;
        }
        else
        {
            break;
        }
      }
      st.insert({arr[n-1],n-1});
      int ans=n-1;
      for(int i=n-2;i>=0;i--)

      {
        if(left[i]==true)
        {
              ans=min(ans,n-(i+1));
        }
         if(right[i]==true)
        {
              ans=min(ans,i);
        }
        if(left[i]==true && st.lower_bound({arr[i],0})!=st.end())
        {
           auto itr=st.lower_bound({arr[i],0});
           ans=min(ans,itr->second-i-1);
          
           cout<<ans<<" "<<i<<" "<<itr->second<<endl; 

        }
       
        if(right[i]==true)
        {
            
            st.insert({arr[i],i});
        }
       
      }
      for(auto itr:st)
      {
        cout<<itr.first<<" "<<itr.second<<endl;
      }
      return ans;
     
    }
};