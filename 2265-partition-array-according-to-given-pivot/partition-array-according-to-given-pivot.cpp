class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
      vector<int>less,la,eq;
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]<pivot)
        {
            less.push_back(nums[i]);
        }
        if(nums[i]>pivot)
        {
            la.push_back(nums[i]);
        }
        if(nums[i]==pivot)
        {
            eq.push_back(nums[i]);
        }
      }  
      vector<int>ans;
      for(int i=0;i<less.size();i++)
      {
        ans.push_back(less[i]);
      }
      for(int i=0;i<eq.size();i++)
      {
        ans.push_back(eq[i]);
      }
      for(int i=0;i<la.size();i++)
      {
        ans.push_back(la[i]);
      }
      return ans;

    }
};