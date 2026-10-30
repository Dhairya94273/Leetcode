class Solution {
public:
    vector<string> ans;

    void remove(string s, int start, int last, bool reversed) {

        int balance = 0;

        for(int i = start; i < s.length(); i++) {

            if(s[i] == (reversed ? ')' : '(')) {
                balance++;
            }
            else if(s[i] == (reversed ? '(' : ')')) {
                balance--;
            }

            if(balance < 0) {

                for(int j = last; j <= i; j++) {

                    if(s[j] == (reversed ? '(' : ')') && (j == last || s[j - 1] != (reversed ? '(' : ')'))) {
                        string next = s.substr(0, j) + s.substr(j + 1);
                        remove(next, i, j, reversed);
                    }
                }
                return;
            }
        }
        if(!reversed) {
            reverse(s.begin(), s.end());
            remove(s, 0, 0, true);
        } else {
            reverse(s.begin(), s.end());
            ans.push_back(s);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        remove(s, 0, 0, false);
        return ans;
    }
};