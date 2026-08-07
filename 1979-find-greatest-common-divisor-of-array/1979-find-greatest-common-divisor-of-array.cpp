class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int a= nums[0];
        int b = nums.back();

        int ans = 1;

        for(int i=1 ; i<=min(a,b) ; i++){
            if(a%i==0 && b%i==0){
                ans=i;
            }
        }
        return ans;
    }
};