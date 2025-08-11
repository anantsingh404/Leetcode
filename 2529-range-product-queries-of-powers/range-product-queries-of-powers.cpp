class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& q)
    { 
        vector<int>temp;
        int nn=n;
     for(int i=30;i>=0;i--)
     {
        if(pow(2,i)<=nn)
        {
            nn-=pow(2,i);
            temp.push_back(pow(2,i));
        }
     }
     reverse(temp.begin(),temp.end());
     vector<int>ans;
     int m=temp.size();
     for(auto itr:q)
     {
        int x=itr[0];
        int y=itr[1];
        long long mul=1;
    for(int j=x;j<=y;j++)
    {
      mul=(mul*temp[j])%(long long)(1e9+7);
    }
    ans.push_back((int)mul);

     }
return ans;


    }
};