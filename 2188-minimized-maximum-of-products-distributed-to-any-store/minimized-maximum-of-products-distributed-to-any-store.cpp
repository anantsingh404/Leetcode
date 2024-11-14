class Solution {
public:
int solve(vector<int>&quant,int sum)
{
    int count=0;
    for(int i=0;i<quant.size();i++)
    {
        count+=quant[i]/sum;
        if(quant[i]%sum)
        {
            ++count;
        }
    }
    return count;
}
    int minimizedMaximum(int n, vector<int>& quant) {
        int maxi=*max_element(quant.begin(),quant.end());
        int mini=1;
        int ans=-1;
        while(mini<=maxi)
        {   
            int mid=(maxi+mini)/2;
            cout<<mid<<endl;
            if(solve(quant,mid)<=n)
            {
                ans=mid;
                maxi=mid-1;
            }
            
            else
            {
                mini=mid+1;
            }
        }
        return ans;
        
    }
};