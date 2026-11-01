class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int count = 0;

        st.push(0);

        for(int i=0 ; i<s.length() ; i++){
            if(s[i] == '('){
                st.push(0);
            }
            
            if(s[i] == ')'){
                int inside = st.top();
                st.pop();

                if(inside == 0){
                    count = 1;
                } else {
                    count = 2*inside;
                }
                st.top() += count;
            }
        }
        return st.top();
    }
};