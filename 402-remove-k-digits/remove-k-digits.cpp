class Solution {
public:
   string removeKdigits(string s, int k) {
    stack<int> st;
    
    for(int i = 0; i < s.size(); i++) {
        int x = s[i] - '0';
        
        while(k && !st.empty() && st.top() > x) {
            st.pop();
            --k;
        }

        // Allow pushing 0 if stack is not empty or x is non-zero
        if(!st.empty() || x != 0) {
            st.push(x);
        }
    }

    // Remove remaining digits if k > 0
    while(k-- && !st.empty()) {
        st.pop();
    }

    if(st.empty()) {
        return "0";
    }

    string res;
    while(!st.empty()) {
        res.push_back(st.top() + '0');
        st.pop();
    }

    reverse(res.begin(), res.end());

    // Remove leading zeros
    int i = 0;
    while(i < res.size() && res[i] == '0') {
        i++;
    }

    res = res.substr(i);
    
    if(res.empty()) {
        return "0";
    }

    return res;
}

};