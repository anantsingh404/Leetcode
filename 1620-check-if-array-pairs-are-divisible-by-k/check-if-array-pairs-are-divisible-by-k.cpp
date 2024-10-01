class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int zero=0;
        int n=arr.size();
        vector<int>freq(k,0);
      for(int i =0;i<arr.size();i++)
      { 
        arr[i]=(arr[i]%k+k)%k;
        if(arr[i]==0)
        {
            ++zero;
        }
        freq[arr[i]]++;
      } 
     if(freq[0]%2)
     {
        return false;
     }
     for(int i=1;i<=k/2;i++)
     {
        if(freq[i]!=freq[k-i])
        {
            return false;
        }
     }
     return true;
    }
};