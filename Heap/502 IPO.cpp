class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        int n = profits.size();

        // Step 1: Store projects as (capital, profit) pairs
        for (int i = 0; i < n; i++) {
            projects.emplace_back(capital[i], profits[i]);
        }

        // Step 2: Sort projects by capital (ascending)
        sort(projects.begin(), projects.end());

        // Max-Heap for profits
        priority_queue<int> profitMaxHeap;
        int i = 0;

        // Step 3: Process k projects
        while (k--) {
            // Add all projects we can afford into the max-heap
            while (i < n && projects[i].first <= w) {
                profitMaxHeap.push(projects[i].second);
                i++;
            }

            // If no project is available, stop
            if (profitMaxHeap.empty()) break;

            // Pick the most profitable available project
            w += profitMaxHeap.top();
            profitMaxHeap.pop();
        }

        return w;
    }
};
