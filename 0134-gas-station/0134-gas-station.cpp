class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { // O(n)
        int totalgas = 0, totalcost = 0;

        int start = 0, currgas = 0, n = gas.size();

        for (int i = 0; i < n; i++) {
            totalgas += gas[i];
            totalcost += cost[i];

            currgas += (gas[i] - cost[i]);
            if (currgas < 0) {
                start = i + 1;
                currgas = 0;
            }
        }
        return totalgas < totalcost ? -1 : start;
    }
};