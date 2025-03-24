class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n=meetings.size();
        vector<vector<int>> temp;
        int a=-1;
        int b=-1;
        for(int i=0;i<n;i++){
           if(a==-1 && b==-1){
            a=meetings[i][0];
            b=meetings[i][1];
            continue;
           } 
           if(meetings[i][0]<=b){
              //overlap
              a=min(a,meetings[i][0]);
              b=max(b,meetings[i][1]);
           }else{
              temp.push_back({a,b});
              a=meetings[i][0];
              b=meetings[i][1];
           }
        }
        if(a!=-1 && b!=-1){
            temp.push_back({a,b});
        }
        // for(auto it:temp){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
        int prev=0;
        n=temp.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int u=temp[i][0];
            int v=temp[i][1];
            if(u>prev){
                ans+=(u-prev-1);
            }
            prev=v;
        }
        ans+=(days-prev);
        return ans; 
    }
};