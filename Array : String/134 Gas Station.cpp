class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int totalGas = 0, totalCost = 0, tank = 0, start = 0;
            
            for (int i = 0; i < gas.size(); i++) {
                totalGas += gas[i];
                totalCost += cost[i];
                tank += gas[i] - cost[i];
                
                // If tank goes negative, reset start position
                if (tank < 0) {
                    start = i + 1;
                    tank = 0;
                }
            }
            
            return (totalGas < totalCost) ? -1 : start;
        }
    };
    