class MyCalendar {
public:
vector<pair<int,int>>st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto itr:st)
        {
            int rs=itr.first;
            int re=itr.second;
            if(start<re && end>rs)
            {
                return false;
            }
        }
        st.push_back({start,end});
        return true;


        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */