class Solution {
public:
    int minimumPushes(string word) {
      unordered_map<char,int>mp;
      for(int i=0;i<word.size();i++)
      {
        mp[word[i]]++;
      } 
      if(mp.size()<=8)
      {
        return word.size();
      }
      vector<int>temp;
      for(auto itr:mp)
      {
        temp.push_back(itr.second);
      }
     // cout<<temp.size();
      sort(temp.begin(),temp.end());
      int sum=0;
      int count=0;
      for(int i=temp.size()-1;i>=0;i--)
      {
        ++count;
        if(count<=8)
        {
            sum+=temp[i];
        }
        else if(count>8 && count<=16)
        {
            sum+=temp[i]*2;
        }
        else if(count>16 && count<=24)
        {
            sum+=temp[i]*3;
        }
        else
        {
            sum+=temp[i]*4;
        }
        cout<<sum<<endl;
      }
      return sum;

    }
};