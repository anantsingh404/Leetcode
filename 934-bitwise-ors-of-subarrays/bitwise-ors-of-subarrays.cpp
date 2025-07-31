class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
       int n=arr.size();
       unordered_set<int>prev,res;
       for(int i=0;i<arr.size();i++)
       {
        unordered_set<int>cc;
        cc.insert(arr[i]);
        for(int itr:prev)
        {
           cc.insert(itr|arr[i]);
        }
        res.insert(cc.begin(),cc.end());
        prev=cc;
       }
       return (int)res.size();

    }
};