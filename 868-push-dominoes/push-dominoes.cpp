class Solution {
public:
    string pushDominoes(string d) 
    {
      int n=d.size();  
      int i=0;
      int j=0;
      string ans;
      while(i<n)
      {
        if(d[i]!='.')
        {
            if(d[i]=='L')
            {
                if(ans.empty())
                {
                     int k=0; 
                    while(k<i)
                    {
                        ans+='L';
                        k++;
                    }
                }
                else if(ans.back()=='L')
                {
                    int k=i-j-1;
                    while(k--)
                    {
                        ans+='L';
                        
                    }
                }
                else
                {
                    int x=(i-j-1);
                    int k=0; 
                    
                    while(k<x/2 && x)
                    {
                        ans+='R';
                        k++;
                    }
                    if(x%2)
                    {
                        ans+='.';
                    }
                    k=0;
                     while(k<x/2)
                    {
                        ans+='L';
                        k++;
                    }
                }
            }
            else
            {
                if(ans.empty())
                {
                      int k=0; 
                    while(k<i)
                    {
                        ans+='.';
                        k++;
                    }
                }
 else if(ans.back()=='R')
                {
                    int k=i-j-1;
                    while(k--)
                    {
                        ans+='R';
                        
                    }
                }
                else
                {
                    int x=(i-j-1);
                    int k=0; 
                    
                    while(k<x && x)
                    {
                        ans+='.';
                        k++;
                    }
                   
                }
        }
      
      }
        if(d[i]!='.')
        {
            ans+=d[i];
        }
        if(d[i]!='.')
        {
            j=i;
        }
        i++;
        }
      if(ans.size()<n)
      {
        if(!ans.empty() && ans.back()=='R')
        {
            int x=n-(int)ans.size();
            while(x--)
            {
                ans+='R';
            }
        }
        else
        {
            int x=n-(int)ans.size();
            while(x--)
            {
                ans+='.';
            }
        }
        
      }
      if(ans.empty())
      {
        return d;
      }
      return ans;
    }
};