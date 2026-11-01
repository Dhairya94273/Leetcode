class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            }
            else {
                if(st.empty() && s[i] ==')'){
                    count++;
                } else{
                    st.pop();
                }       
            }
        }
        return count + st.size();
    }
};