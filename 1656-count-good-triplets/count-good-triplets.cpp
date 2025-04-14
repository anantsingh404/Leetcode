class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count=0;
        int n=arr.size();
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+2;j<n;j++)
            {
                if(abs(arr[i]-arr[j])<=c)
                {
                    int k=i+1;
                    while(k<j)
                    {
                        if(abs(arr[i]-arr[k])<=a && abs(arr[k]-arr[j])<=b)
                        {
                            ++count;
                        }
                        ++k;
                    }

                }
            }
        }
        return count;
    }
};