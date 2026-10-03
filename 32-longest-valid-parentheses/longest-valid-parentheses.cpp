class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>>as;
        vector<int>arr(s.size(),0);
        if(s.empty() || s.size()==1)
        {
            return 0;
        }
        for(int i=0;i<s.size();i++)
        {
            if(as.empty())
            {
                as.push({s[i],i});
            }
            else if(as.top().first=='(' && s[i]==')')
            {   arr[as.top().second]=1;
                as.pop();
                
                arr[i]=1;
            }
            else
            {
              as.push({s[i],i});
            }
        }
        int sum=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
            {
                sum=0;
            }
            else
            {
                sum=sum+arr[i];
                maxi=max(maxi,sum);
            }
        }
       // cout<<arr[0]<<arr[1]<<arr[2]<<endl;
        return maxi;
    }
};