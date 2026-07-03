class Solution {
public:
    void sortColors(vector<int>& A) {
        int n=A.size();
        int low=0 , mid=0 , high = n-1;

        while(mid <= high){
            if(A[mid] == 0){ //check for 0
                swap(A[low] , A[mid]);
                mid++;
                low++ ;
            } else if(A[mid] == 1){ //check for 1
                mid++;
            } else { // check for 2
                swap(A[high] , A[mid]);
                high--; 
            }
        }
    }
};