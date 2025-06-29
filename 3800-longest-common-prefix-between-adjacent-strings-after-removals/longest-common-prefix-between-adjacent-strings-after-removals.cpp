class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
     int n=words.size();
     if(n==1)
     {
        return {0};
     }
     if(n==2)
     {
        return {0,0};
     }
     vector<int>left(n,0);
     vector<int>right(n,0);
     for(int j=1;j<n;j++)
     {   int maxi=0;
          while(maxi<min(words[j].size(),words[j-1].size()))
        {
            if(words[j][maxi]!=words[j-1][maxi])
            {
                break;
            }
            else
            {
                ++maxi;
            }
        }
        left[j]=max(left[j-1],maxi);
     }
    // vector<int>right(n,0);
     for(int j=n-2;j>=0;j--)
     {   int maxi=0;
       while(maxi<min(words[j].size(),words[j+1].size()))
        {
            if(words[j][maxi]!=words[j+1][maxi])
            {
                break;
            }
            else
            {
                ++maxi;
                
            }
        }
        right[j]=max(right[j+1],maxi);
     }
     vector<int>ans;
     for(int i=0;i<n;i++)
     {
        int temp=0;
        if(i+1<n)
        {
            temp=max(temp,right[i+1]);
        }
        if(i-1>=0)
        {
            temp=max(temp,left[i-1]);
        }
        if(i-1>=0 && i+1<n)
        {
            int maxi=0;
            while(maxi<min(words[i-1].size(),words[i+1].size()))
            {
                if(words[i-1][maxi]!=words[i+1][maxi])
                {
                    break;
                }
                else
                {
                    ++maxi;
                }
            }
            temp=max(temp,maxi);
           
        }
         ans.push_back(temp);
     }
     return ans;

    }
};