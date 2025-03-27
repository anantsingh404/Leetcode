class Solution {
public:
    int minimumIndex(vector<int>& nums) {
      int num=nums[0];
      int count=0;
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]==num)
        {
            ++count;
        }
        else
        {
        if(count>0)
        {
            --count;
        }
        else
        {
            count=1;
            num=nums[i];
        }
        }
      }
      
      int cc=0;
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]==num)
        {
            ++cc;
        }
      } 
      int n=nums.size();
      //cout<<cc<<" "<<num<<endl;
      if(cc > (nums.size()/2))
      { 
        int temp=0;
    
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]==num)
           {
            ++temp;
            --cc;
           }
           cout<<temp<<endl;
           if(((temp)*2)>(i+1) && (n-i-1)<(cc*2))
           {
               return i;
           }
        }
      } 
      return -1;
    }
};