/*
There are N books, each ith book has A[i] number of pages. 
you have Allocate books to M number of students so that the maximum number of pages allocated to a student is minimum
Each Student should be allocated to the student.
Each Student has to be allocated at least one book.
Allocate should be in contiguous order.
Calculate and return the minimum possible number of maximum pages that can be allocated to a student.
Return -1 if a valid assignment is not possible.

For example:
arr = [2,1,3,4] , N=4 ,  M=2

1) S1 = 2    S2 = 1+3+4 = 8  in first way maximum number of pages allocated to a student is 8
2) S1 = 2+1 = 3    S2 = 3+4 = 7 in second way maximum number of pages allocated to a student is 7
3) S1 = 2+1+3 = 6    S2 = 4 in third way maximum number of pages allocated to a student is 6
Now the minimum of these maximums is 6, which is the answer.

Now Q) What is the example in which we don't allocate the books to the students?
    ans :- M>N if M=5 in previous example then we can't allocate the books to the students because we have only 4 books 
           and 5 students. So, the answer will be -1.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr,int N , int M,int maxAllowedPages){//O(n)
    int stu=1 , pages=0;
    for(int i=0 ; i<N ; i++){
        if(arr[i] > maxAllowedPages){
            return false;
        }
        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        } else {
            stu++;
            pages = arr[i];
        }
    }
    if(stu > M){
        return false;
    } else {
        return true;
    }
}

int sum(vector<int> &arr , int n){//O(n)
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int allocateBooks(vector<int> &arr , int N , int M){//O(logN * n);N=Range,n=total book
    if(M>N){
        return -1;
    }
    int st=0 , end = sum(arr , N);
    int ans = -1;
    while(st <= end){
        int mid = st+(end-st)/2;
        if(isValid(arr,N,M,mid)){//valid case then we have to search in left side
            ans = mid;
            end = mid-1;
        } else {//invalid case then we have to search in right side
            st = mid+1;
        }
    }
    return ans;
}


int main(){
    vector<int> arr = {15,17,20};
    int N = arr.size();
    int M = 2;
    cout << allocateBooks(arr , N , M) << endl;
    return 0;
}