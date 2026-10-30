class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // 1. Build adjacency list: graph[u] = list of {neighbor, weight}
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        // 2. minDistance[node][streak] = best known distance
        vector<vector<int>> minDistance(n, vector<int>(k + 1, INT_MAX));

        // 3. Start at node 0 with streak 1
        minDistance[0][1] = 0;
        // min-heap ordered by {distance, node, streak}
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<>> minHeap;
        minHeap.push({0, 0, 1});

        // 4. Dijkstra over (node, streak) states
        while (!minHeap.empty()) {
            auto [distance, node, streak] = minHeap.top();
            minHeap.pop();

            if (node == n - 1) {
                return distance;
            }
            if (distance > minDistance[node][streak]) {
                continue; // stale entry
            }

            // 5. Relax outgoing edges
            for (auto& [neighbor, weight] : graph[node]) {
                int nextStreak = (labels[neighbor] == labels[node]) ? streak + 1 : 1;
                int nextDistance = distance + weight;

                if (nextStreak <= k && nextDistance < minDistance[neighbor][nextStreak]) {
                    minDistance[neighbor][nextStreak] = nextDistance;
                    minHeap.push({nextDistance, neighbor, nextStreak});
                }
            }
        }

        // 6. Target unreachable under the constraint
        return -1;
    }
};