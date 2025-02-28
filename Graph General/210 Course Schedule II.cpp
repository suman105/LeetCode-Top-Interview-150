class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> order;
        
        // Build adjacency list and in-degree array
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            graph[prereq].push_back(course);  // prereq → course
            inDegree[course]++;
        }

        // Initialize queue with courses having no prerequisites (in-degree = 0)
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS Process
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);

            for (int nextCourse : graph[course]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // If we processed all courses, return the order, else return []
        return (order.size() == numCourses) ? order : vector<int>();
    }
};
