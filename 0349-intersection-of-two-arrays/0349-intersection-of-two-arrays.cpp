class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        sort(nums2.begin(), nums2.end());

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {

            int st = 0;
            int end = nums2.size() - 1;

            while(st <= end) {

                int mid = st + (end - st) / 2;

                if(nums2[mid] == nums1[i]) {
                    ans.push_back(nums1[i]);
                    break;
                }
                else if(nums2[mid] < nums1[i]) {
                    st = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};