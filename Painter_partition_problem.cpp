/*
Given are N boards of length of each given in the form of an array,and M Painters,Such
that each painter takes 1 unit of time to paint 1 unit of the board.

The Task is to find the minimum time to paint all boards under the constaints that any painter will only paint 
continuos section of boards.
*/
#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> board){
    int sum = 0;
    for(int i=0 ; i<board.size() ; i++){
        sum += board[i];
    }
    return sum;
}

int max(vector<int> board){
    int max = board[0];
    for(int i=1 ; i<board.size() ; i++){
        if(board[i] > max){
            max = board[i];
        }
    }
    return max;
}

bool isValid(vector<int> board , int m , int max_time){
    int painter=1;
    int time=0;
    for(int i=0 ; i<board.size() ; i++){
        if(board[i] > max_time){
            return false;
        }
        if(time + board[i] <= max_time){
            time+=board[i];
        } else {
            painter++;
            time = board[i];   
        }
    }
    if(painter > m){
        return false;
    } else {
        return true;
    }
}

int painter(vector<int> board , int n , int m){
    int st = max(board);
    int end = sum(board);
    int ans = -1;

    while(st <= end){
        int mid = st + (end - st)/2;
        if(isValid(board , m , mid)){
            ans = mid;
            end = mid - 1;
        } else {
            st = mid+1;
        }
    }
    return ans; 
}

int main(){
    vector<int> board = {40,30,10,20};
    int M = 2;
    int N = 4;
    int ans = painter(board,N,M);
    cout << "Possible minimum time to paint Board is : " << ans << endl;
    return 0;
}