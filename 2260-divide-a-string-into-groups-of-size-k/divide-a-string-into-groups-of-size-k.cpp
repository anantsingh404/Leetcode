class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
     int i=0;
     int n=s.size();
     vector<string>ans;
     while(i<n)
     {
        if(i+k<=n)
        {
            ans.push_back(s.substr(i,k));
            i+=k;
        }
        else
        {
            ans.push_back(s.substr(i,n-i));
            break;
        }
     }
     while(ans.back().size()<k)
     {
        ans.back().push_back(fill);
     }  
     return ans; 
    }
};