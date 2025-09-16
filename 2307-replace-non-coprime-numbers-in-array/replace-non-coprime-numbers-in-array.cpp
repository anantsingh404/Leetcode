class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
       stack<long long>st;
       st.push(1ll*nums[0]);
       int n=nums.size();
       for(int i=1;i<n;i++){
        long long x=nums[i];
    
        if(!st.empty() && __gcd(st.top(),1ll*nums[i])>1)
        {
           long long y=st.top();
           st.pop();
           st.push((1ll*y*x)/__gcd(x,y));
           while(st.size()>=2)
           {
            long long xx=st.top();
            st.pop();
            long long yy=st.top();
            st.pop();
            long long zz=__gcd(xx,yy);
            if(zz>1)
            {
                st.push((xx*yy)/zz);
            }
            else
            {
                st.push(yy);
                st.push(xx);
                break;
            }

           }
        }else
        {
            st.push(x);
        }
       }
       vector<int>ans;
       while(!st.empty())
       {
        ans.push_back((int)st.top());
        st.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;

    }
};