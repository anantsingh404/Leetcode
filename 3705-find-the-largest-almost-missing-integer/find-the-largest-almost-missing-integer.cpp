class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
     int n=nums.size();
     unordered_map<int,int>fa;
     unordered_map<int,int>la;
     for(int i=0;i<n;i++)
     {
        if(fa.find(nums[i])!=fa.end())
        {
            la[nums[i]]=i;
        }
        else
        {
            fa[nums[i]]=i;
            la[nums[i]]=i;
        }
     }
     if(k==n)
     {
        return *max_element(nums.begin(),nums.end());
     }
     
     if(k==1)
     { int emp=-1;
       for(auto itr:fa){
        int x=itr.second;
        int y=la[itr.first];
        if(x!=y){
            continue;
        }
        else if(itr.first>emp)
        {
            emp=itr.first;
        }
     }
     return emp;      
     }
     if(k>n)
     {
        return -1;
     }
     if(la[nums[0]]-fa[nums[0]]!=0 && la[nums[n-1]]-fa[nums[n-1]]!=0)
     {
        return -1;
     }
     if(la[nums[0]]-fa[nums[0]]!=0) 
     {
        return nums[n-1];
     } 
     if(la[nums[n-1]]-fa[nums[n-1]]!=0) {
        return nums[0];
     } return max(nums[0],nums[n-1]);

    }
};