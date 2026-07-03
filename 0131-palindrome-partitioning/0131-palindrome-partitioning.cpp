class Solution {
public:
    bool isPalindrom(string s){
        string s2 = s;
        reverse(s2.begin() , s2.end());
        return s==s2;
    }
    void getAllParts(string s , vector<vector<string>> &ans , vector<string> &partition){
        int n= s.length();
        if(s.length() == 0){
            ans.push_back(partition);
            return;
        }
        for(int i=0 ; i<n ; i++){
            string part = s.substr(0 , i+1);
            if(isPalindrom(part)){
                partition.push_back(part);
                getAllParts(s.substr(i+1),ans,partition);//If a palindrome partition is found, recursively find the remaining partitions.
                partition.pop_back(); //We backtrack to remove the previously chosen palindrome from the partition array so we can explore the next possible palindrome partition.
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        getAllParts(s,ans,partition);
        return ans;
    }
};