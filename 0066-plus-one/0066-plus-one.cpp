class Solution { 
public: 
    vector<int> plusOne(vector<int>& digits) { 
        for(int i = digits.size() - 1; i >= 0; i--) { 
            if(digits[i] < 9) { 
                digits[i]++; 
                return digits; 
            } 
            digits[i] = 0; 
        } 
        // Moved these lines outside of the class block, before the closing brace
        digits.insert(digits.begin(), 1); 
        return digits; 
    } 
};
