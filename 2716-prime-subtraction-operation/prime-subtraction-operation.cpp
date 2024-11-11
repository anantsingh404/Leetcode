class Solution {
public:
bool isprime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}
    bool primeSubOperation(vector<int>& nums) {
      vector<int>prime;
      int count=0;
      int n=nums.size();

      for(int i=2;i<=1000;i++)
      {
        if(isprime(i))
        {
            prime.push_back(i);
        }
      }
      for(int i=n-2;i>=0;i--)
      {
        if(nums[i]<nums[i+1])
        {
            continue;
        }
        else
        {  auto itr=lower_bound(prime.begin(),prime.end(),nums[i]-nums[i+1]+1);
        if(itr==prime.end())
        {
            return false;
        }
            int x=*lower_bound(prime.begin(),prime.end(),nums[i]-nums[i+1]+1);
            nums[i]-=x;
            if(nums[i]<=0)
            {
                return false;
            }
            ++count;
        }
      }
      return true;  
    }
};