class Solution {
public:
    int move_hor[4] = {-1, 0, 1, 0};
    int move_ver[4] = {0, -1, 0, 1};
    int ROW;
    int COL;
    int dijkstra(vector<vector<int>>& heights, vector<vector<int>>& min_effort) {
        min_effort[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto tmp = pq.top();
            int eff = -tmp.first;
            int idx_r = tmp.second.first;
            int idx_c = tmp.second.second;
            if (idx_r == ROW-1 && idx_c == COL-1) return min_effort[ROW-1][COL-1];
            pq.pop();
            for (int i=0; i<4; i++) {
                int new_row = idx_r + move_hor[i];
                int new_col = idx_c + move_ver[i];
                if (new_row < ROW && new_row > -1 && new_col < COL && new_col > -1) {
                    int cost = max(eff, abs(heights[new_row][new_col] - heights[idx_r][idx_c]));
                    if (cost < min_effort[new_row][new_col]) {
                        min_effort[new_row][new_col] = cost;
                        pq.push({-cost, {new_row, new_col}});
                    }
                }
            }
        }
        return min_effort[ROW-1][COL-1];

    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        ROW = heights.size();
        COL = heights[0].size();
        vector<vector<int>> min_effort(ROW, vector<int>(COL, 1e9));
        return dijkstra(heights, min_effort);
    }
};
