class Solution {
public:
    string answerString(string word, int nf) {
       int n=word.size();
      int count=n-nf+1;
      char xx='a';
      if(nf==1)
      {
        return word;
      }
      for(int i=0;i<n;i++)
      {
        if(word[i]>xx)
        {
            xx=word[i];
        }
      }
      int k=0;
      priority_queue<string>pq;
      while(k<n)
      {
         if(word[k]==xx)
        {
        string x=word.substr(k,min(count,n-k));
         pq.push(x);
        }
       
        k++;
      }
      return pq.top();


    }
};