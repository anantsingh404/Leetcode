class Solution {
public:
    int minDominoRotations(vector<int>& top, vector<int>& bottom) {
     unordered_map<int,int>mp;
     int tn=-1;
     int n=top.size();
     int cc=0;
      int x=-1;
     for(int i=0;i<n;i++)
     {   if(top[i]==bottom[i])
         {   if(x==-1){
             x=top[i];
             }
             ++cc;
        continue;
        }
        
        mp[top[i]]++;
        mp[bottom[i]]++;
        
     }
       for(int i=0;i<n;i++)
     {
        if(x!=-1 && top[i]!=x && bottom[i]!=x)
        {
            return -1;
        }
     }
     if(!mp.size())
     {
return 0;
     } 
     int maxi=0;
     int dig=-1;
     for(auto itr:mp)
     {
       if(itr.second>=n-cc)
        {
            tn=1;
            maxi=max(maxi,itr.second);
            dig=itr.first;
            break;
        }
     }
     cout<<tn<<endl;
     if(tn==-1)
     {
        return -1;
     }
     int c1=0,c2=0;
     for(int i=0;i<n;i++)
     {  if(top[i]==dig && bottom[i]==dig)
     {
        continue;
     }
        if(top[i]==dig)
        {
            ++c1;
        }
        if(bottom[i]==dig)
        {
            ++c2;
            }
     }
     cout<<c1<<" "<<c2<<endl;
      if(c1>=n-cc ||c2>=n-cc)
     {
        return 0;
     }
     c1=min(n-cc,c1);
     c2=min(n-cc,c2);
     return n-cc-max(c1,c2);

    }
};