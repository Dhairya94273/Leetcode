class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0 , candidate = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(freq == 0){
                candidate = nums[i];
            }
            if(candidate == nums[i] ){
                freq++;
            } else {
                freq--;
            }
        }
        return candidate;
    }
};