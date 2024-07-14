#define pappu map<string,int> 
class Solution {
public:
  
    string countOfAtoms(string f) {
        int n=f.size();
     stack<pappu>st; 
     st.push({});
     int i=0;
     while(i<n)
     {
        if(f[i]=='(')
        {
            st.push({});
            i++;
        }
        else if(f[i]==')')
        {
            pappu x=st.top();
            st.pop();
            i++;
            int pehla=i;
            while(i<n && isdigit(f[i]))
            {
                i++;
            }
            int mult=pehla<i?stoi(f.substr(pehla,i-pehla)):1;
            for(auto &itr:x)
            {
                st.top()[itr.first]+=itr.second*mult;
            }
        }
        else
        {
            int start=i++;
            while(i<n && islower(f[i]))
            {
                i++;
            }
            string metal=f.substr(start,i-start);
            start=i;
             while (i < n && isdigit(f[i])) {
                    i++;
                }
            
            int count=start<i?stoi(f.substr(start,i-start)):1;
            st.top()[metal]+=count;
        }
     }
     map<string,int>res=st.top();
     vector<string>ans;
     for(auto &itr:res)
     {
        ans.push_back(itr.first);
     }
     sort(ans.begin(),ans.end());
     string result;
     for(int i=0;i<ans.size();i++)
     {
        result+=ans[i];
        if(res[ans[i]]>1)
        {
            result+=to_string(res[ans[i]]);
        }
     }
     return result;
     
    }
};