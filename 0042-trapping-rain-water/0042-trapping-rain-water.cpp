class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;
        int sum = 0;
        while (l < r) {
            lmax = max(lmax, height[l]); // calculate an left and Right Boundries for an Perticular bar
            rmax = max(rmax, height[r]);
            if (lmax < rmax) { // jo bhi small value he lmax and rmax me voh deciding factor hogi water trap me
                sum += lmax - height[l];
                l++;
            } else {
                sum += rmax - height[r];
                r--;
            }
        }
        return sum;
    }
};