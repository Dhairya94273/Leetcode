class Solution {
public:
    int findMin(vector<int>& A) {
        int st = 0, end = A.size() - 1;
        
        while (st < end) {
            int mid = st + (end - st) / 2;
            
            // If mid is greater than end, the minimum must be in the right half
            if (A[mid] > A[end]) {
                st = mid + 1;
            } 
            // Otherwise, mid could be the minimum, or the minimum is in the left half
            else {
                end = mid;
            }
        }
        return A[st]; // st and end converge at the minimum element
    }
};

