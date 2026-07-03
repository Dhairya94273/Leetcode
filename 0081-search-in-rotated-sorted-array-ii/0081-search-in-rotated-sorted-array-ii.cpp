class Solution {
public:
    bool search(vector<int>& A, int target) {
        int n = A.size();
        int st = 0 , end = n-1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(A[mid] == target){
                return true;
            }

            //Duplicates cannot be decided sorted half
            if (A[st] == A[mid] && A[mid] == A[end]) {
                st++;
                end--;
            } else  if(A[st] <= A[mid]){// left half sorted
                if(A[st] <= target && target <= A[mid]){
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }

            } else { // right half sorted
                if(A[mid] < target && target <= A[end]){
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};