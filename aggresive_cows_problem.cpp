/*
Assign C cows to N stalls such that min distance between them is largest possible
Return the largest minimum distance
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min(vector<int> cows) {
    int mn = cows[0];
    for(int i = 0; i < cows.size(); i++) {
        if(cows[i] < mn) {
            mn = cows[i];
        }
    }
    return mn;
}

int max(vector<int> cows) {
    int mx = cows[0];
    for(int i = 0; i < cows.size(); i++) {
        if(cows[i] > mx) {
            mx = cows[i];
        }
    }
    return mx;
}

bool isValid(vector<int> cows, int c, int min_cows) {
    int cow = 1;
    // First cow is placed at first stall
    int lastPosition = cows[0];
    for(int i = 1; i < cows.size(); i++) {
        int distance = cows[i] - lastPosition;
        if(distance >= min_cows) {
            cow++;
            lastPosition = cows[i];
        }
        if(cow >= c) {
            return true;
        }
    }
    return false;
}

int aggresive_cows(vector<int> cows, int c, int n) {
    sort(cows.begin(), cows.end());
    int st = 1;
    int end = max(cows) - min(cows);
    int ans = -1;
    while(st <= end) {
        int mid = st + (end - st) / 2;
        if(isValid(cows, c, mid)) {
            ans = mid;
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> cows = {1, 2, 8, 4, 9};
    int c = 3;
    int n = 5;
    cout << "Largest Minimum Distance is : " << aggresive_cows(cows, c, n) << endl;
    return 0;
}