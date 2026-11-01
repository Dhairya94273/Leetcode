class Solution {
public:
    bool checkValidString(string s) {

        int minOpen = 0;
        int maxOpen = 0;

        for (char ch : s) {

            if (ch == '(') {
                minOpen++;
                maxOpen++;
            }
            else if (ch == ')') {
                minOpen--;
                maxOpen--;
            }
            else { // '*'
                minOpen--; // '*'  as  ')'

                maxOpen++; // '*' as '('
            }

            if (maxOpen < 0) { // Too many closing brackets
                return false;
            }

            if (minOpen < 0) {   // Minimum cannot be negative
                minOpen = 0;
            }
        }

        return minOpen == 0;
    }
};