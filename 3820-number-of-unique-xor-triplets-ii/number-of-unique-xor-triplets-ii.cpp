class Solution {
public:
    int uniqueXorTriplets(vector<int>& num) {
    set<int>st(num.begin(),num.end());
    vector<int>nums;
    for(int itr:st)
    {
        nums.push_back(itr);
    }
    unordered_set<int>st1;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=0;j<nums.size();j++)
        {
            st1.insert(nums[i]^nums[j]);
        }
    }
    unordered_set<int>st2;
    for(int itr:st1)
    {
        for(int i=0;i<nums.size();i++)
        {
            st2.insert(itr^nums[i]);
        }
    }
    vector<int>ans;
    for(int itr:st2)
    {
        ans.push_back(itr);
    }
    sort(ans.begin(),ans.end());
    return (int)ans.size();




    }
};