class Solution {
public:
    string smallestPalindrome(string s) {
     vector<int>arr(26,0);
     int n=s.size();
     for(int i=0;i<n;i++)
     {
        arr[s[i]-'a']++;
     }
       //cout<<arr[9]<<endl;
     string ans="";
     for(int i=0;i<26;i++)
     {
        int k=arr[i]/2;
       // cout<<k<<endl;
        while(k>0)
        {
            ans.push_back(('a'+i));
            --k;
        }
       
        arr[i]=arr[i]%2;
       
     } 
    // cout<<ans<<endl;
      string temp=ans;
     for(int i=0;i<26;i++)
     {
        if(arr[i]>0)
        {
            ans.push_back('a'+i);
        }
     }
    
     reverse(temp.begin(),temp.end());
     if(n>1)
     {
           return ans+temp;  
     }
     return ans;
    
    }
};