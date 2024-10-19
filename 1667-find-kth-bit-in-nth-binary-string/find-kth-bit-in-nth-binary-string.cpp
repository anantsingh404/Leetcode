class Solution {
public:
    char findKthBit(int n, int k) {
        string ans;
        ans.push_back('0');
        string flag;
        if(n==1)
        {
            return ans[0];
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<ans.size();j++)
            {
                if(ans[j]=='0')
                {
                    flag.push_back('1');
                }
                else
                {
                    flag.push_back('0');
                }
            }
            reverse(flag.begin(),flag.end());
            ans.push_back('1');
            ans+=flag;
            flag.clear();
            
        }
        return ans[k-1];
    }
};